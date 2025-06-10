#include "editor.h"
#include "common.h"

#include <chrono>
#include <cstring>
#include <optional>
#include <sys/ioctl.h> // For ioctl()
#include <termios.h>
#include <termios.h> // For struct winsize
#include <unistd.h>
#include <unistd.h> // For STDOUT_FILENO

// ANSI escape sequences
#define CURSOR_POS(row, col) "\033[" + std::to_string((row)) + ";" + std::to_string((col)) + "H"
#define REVERSE_ON "\033[7m"
#define REVERSE_OFF "\033[0m"
#define HIDE_CURSOR "\033[?25l"
#define SHOW_CURSOR "\033[?25h"

termios orig_termios;
std::vector<std::string> buffer;
int current_line = 0;
int cursor_col = 0;

std::optional<std::chrono::steady_clock::time_point> max_line_hint_time;

std::string makePrompt(int line_num) {
  return " " + std::to_string(line_num) + " | ";
}

// Move the cursor to a specific position based on line number and column
void moveCursor(int row, int col) {
  std::string prompt = makePrompt(row);
  std::string pos = CURSOR_POS(row + 1, col + prompt.size() + 1);
  write(STDOUT_FILENO, pos.c_str(), pos.size());
}

// Redraw a single line with prompt and cursor position
void redrawLine(int line_num, bool cursor_highlight = true) {
  std::string prompt = makePrompt(line_num);
  std::string output = prompt;

  if (cursor_highlight && line_num == current_line) {
    for (int i = 0; i < (int)buffer[line_num].size(); ++i) {
      if (i == cursor_col) {
        output +=
            REVERSE_ON + std::string(1, buffer[line_num][i]) + REVERSE_OFF;
      } else {
        output += buffer[line_num][i];
      }
    }
    if (cursor_col >= (int)buffer[line_num].size()) {
      output += REVERSE_ON " " REVERSE_OFF;
    }
  } else {
    output += buffer[line_num];
  }

  std::string pos = CURSOR_POS(line_num + 1, 1);
  write(STDOUT_FILENO, pos.c_str(), pos.size());
  write(STDOUT_FILENO, "\033[2K", 4);
  write(STDOUT_FILENO, output.c_str(), output.size());
}

// Clear the full screen area used by the editor
void clearEditorScreen() {
  int content_lines = buffer.size();
  int total_lines = content_lines + 2;
  for (int i = 0; i < total_lines + 1; ++i) {
    std::string pos = CURSOR_POS(i + 1, 1);
    write(STDOUT_FILENO, pos.c_str(), pos.size());
    write(STDOUT_FILENO, "\033[2K", 4);
  }
}

// Redraw all lines and status messages
void redrawAll(bool cursor_highlight = true) {
  static int last_total_lines = 0;
  int content_lines = buffer.size();
  int total_lines = content_lines + 2;
  int max_lines = std::max(last_total_lines, total_lines);

  for (int i = 0; i < max_lines; ++i) {
    std::string pos = CURSOR_POS(i + 1, 1);
    write(STDOUT_FILENO, pos.c_str(), pos.size());
    write(STDOUT_FILENO, "\033[2K", 4);
  }

  for (int i = 0; i < content_lines; ++i) {
    redrawLine(i, cursor_highlight);
  }

  if (cursor_highlight) {
    if (max_line_hint_time) {
      auto now = std::chrono::steady_clock::now();
      auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(
                         now - *max_line_hint_time)
                         .count();
      if (elapsed < 3) {
        std::string warn =
            CURSOR_POS(content_lines + 1, 1) + "[Max line count reached]";
        write(STDOUT_FILENO, warn.c_str(), warn.size());
      } else {
        max_line_hint_time.reset();
      }
    }

    std::string hint =
        CURSOR_POS(content_lines + 2, 1) +
        "Edit Mode: ↑ ↓ ← → | Enter | Backspace | Ctrl+D: submit";
    write(STDOUT_FILENO, hint.c_str(), hint.size());
    moveCursor(current_line, cursor_col);
  }

  last_total_lines = total_lines;
}

// Restore original terminal settings
void disableRawMode() {
  write(STDOUT_FILENO, SHOW_CURSOR, 6);
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

// Set terminal into raw input mode
void enableRawMode() {
  tcgetattr(STDIN_FILENO, &orig_termios);
  atexit(disableRawMode);
  termios raw = orig_termios;
  raw.c_lflag &= ~(ECHO | ICANON);
  raw.c_cc[VMIN] = 1;
  raw.c_cc[VTIME] = 0;
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
  write(STDOUT_FILENO, HIDE_CURSOR, 6);
}

// Determine UTF-8 character width before cursor
int getUtf8CharLengthBefore(const std::string &line, int cursor) {
  if (cursor == 0)
    return 0;
  int i = cursor - 1;
  while (i > 0 && (line[i] & 0xC0) == 0x80)
    --i;
  return cursor - i;
}

// Apply symbol replacements based on trigger sequences (e.g. lambda → λ)
void applyReplacement(std::string &line, int &cursor) {
  int max_len = 10;
  for (int len = 2; len <= max_len && cursor - len >= 0; ++len) {
    std::string substr = line.substr(cursor - len, len);
    if (replacement_table.count(substr)) {
      line.replace(cursor - len, len, replacement_table[substr]);
      cursor = cursor - len + replacement_table[substr].size();
      return;
    }
  }
}

int moveCursorLeft(const std::string &str, int cursor) {
  if (cursor <= 0) return 0;
  --cursor;
  while (cursor > 0 && (str[cursor] & 0xC0) == 0x80) --cursor;
  return cursor;
}

int moveCursorRight(const std::string &str, int cursor) {
  if (cursor >= (int)str.size()) return cursor;
  ++cursor;
  while (cursor < (int)str.size() && (str[cursor] & 0xC0) == 0x80) ++cursor;
  return cursor;
}

// Main editor loop entry
std::optional<std::vector<std::string>> launchEditor() {
  struct winsize ws;
  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_row < 12) {
    return std::nullopt;
  }

  buffer.clear();
  current_line = 0;
  cursor_col = 0;
  max_line_hint_time.reset();

  const char *clear = "\033[2J\033[H";
  write(STDOUT_FILENO, clear, 7);

  enableRawMode();
  buffer.push_back("");
  redrawAll();

  while (true) {
    char c;
    ssize_t n = read(STDIN_FILENO, &c, 1);
    if (n <= 0)
      continue;

    bool needRedrawAll = false;

    if (c == 4) { // Ctrl+D
      redrawAll(false);
      std::string final_cursor = CURSOR_POS(buffer.size() + 2, 1);
      write(STDOUT_FILENO, final_cursor.c_str(), final_cursor.size());
      write(STDOUT_FILENO, "\033[2K", 4);
      disableRawMode();
      return buffer;
    } else if (c == 127 || c == 8) { // Backspace
      if (cursor_col > 0) {
        int len = getUtf8CharLengthBefore(buffer[current_line], cursor_col);
        buffer[current_line].erase(cursor_col - len, len);
        cursor_col -= len;
      } else if (current_line > 0) {
        cursor_col = buffer[current_line - 1].size();
        buffer[current_line - 1] += buffer[current_line];
        buffer.erase(buffer.begin() + current_line);
        current_line--;
        needRedrawAll = true;
        max_line_hint_time.reset();
      }
    } else if (c == '\n') {
      if ((int)buffer.size() >= 10) {
        max_line_hint_time = std::chrono::steady_clock::now();
        redrawAll();
        continue;
      }
      std::string tail = buffer[current_line].substr(cursor_col);
      buffer[current_line].erase(cursor_col);
      buffer.insert(buffer.begin() + current_line + 1, tail);
      current_line++;
      cursor_col = 0;
      needRedrawAll = true;
    } else if (c == '\033') { // Arrow keys
      char seq[2];
      read(STDIN_FILENO, &seq[0], 1);
      read(STDIN_FILENO, &seq[1], 1);
      if (seq[0] == '[') {
        int old_line = current_line;
        if (seq[1] == 'A' && current_line > 0) { // ↑
          current_line--;
          cursor_col = std::min(cursor_col, (int)buffer[current_line].size());
          max_line_hint_time.reset();
        } else if (seq[1] == 'B' && current_line < (int)buffer.size() - 1) { // ↓
          current_line++;
          cursor_col = std::min(cursor_col, (int)buffer[current_line].size());
        } else if (seq[1] == 'C') { // →
          cursor_col = moveCursorRight(buffer[current_line], cursor_col);
        } else if (seq[1] == 'D') { // ←
          cursor_col = moveCursorLeft(buffer[current_line], cursor_col);
        }
        if (seq[1] == 'A' || seq[1] == 'B') {
          redrawLine(old_line);
          redrawLine(current_line);
          moveCursor(current_line, cursor_col);
          continue;
        }
      }
    } else {
      buffer[current_line].insert(cursor_col, 1, c);
      cursor_col++;
      applyReplacement(buffer[current_line], cursor_col);
    }

    if (needRedrawAll) {
      redrawAll();
    } else {
      std::string prompt = makePrompt(current_line);
      std::string output = prompt;

      int idx = 0;
      while (idx < (int)buffer[current_line].size()) {
        int char_end = moveCursorRight(buffer[current_line], idx);
        std::string utf8_char = buffer[current_line].substr(idx, char_end - idx);

        if (idx == cursor_col) {
          output += REVERSE_ON + utf8_char + REVERSE_OFF;
        } else {
          output += utf8_char;
        }

        idx = char_end;
      }

      if (cursor_col >= (int)buffer[current_line].size()) {
        output += REVERSE_ON " " REVERSE_OFF;
      }

      std::string pos = CURSOR_POS(current_line + 1, 1);
      write(STDOUT_FILENO, pos.c_str(), pos.size());
      write(STDOUT_FILENO, "\033[2K", 4);
      write(STDOUT_FILENO, output.c_str(), output.size());

      moveCursor(current_line, cursor_col);
    }
  }

  return {};
}



std::optional<std::string> launchSingleLineEditor(int prompt_id) {
  enableRawMode();

  buffer.clear();
  current_line = 0;
  cursor_col = 0;
  buffer.push_back("");

	// Prompt
  std::string prompt = "In[" + std::to_string(prompt_id) + "]: ";
  std::cout << prompt << std::flush;

	// Cursor
  std::string output = prompt + REVERSE_ON " " REVERSE_OFF;
  std::cout << "\r\033[2K" << output << std::flush;

  while (true) {
    char c;
    ssize_t n = read(STDIN_FILENO, &c, 1);
    if (n <= 0)
      continue;

    if (c == 4) { // Ctrl+D
      std::cout << "\r\033[2K" << prompt << buffer[0] << "\n";
      disableRawMode();
      return std::nullopt;
    } else if (c == '\n') {
      std::cout << "\r\033[2K" << prompt << buffer[0] << "\n";
      disableRawMode();
      return buffer[0];
    } else if (c == 127 || c == 8) { // Backspace
      if (cursor_col > 0) {
        int len = getUtf8CharLengthBefore(buffer[0], cursor_col);
        buffer[0].erase(cursor_col - len, len);
        cursor_col -= len;
      }
    } else if (c == '\033') { // Arrow keys
      char seq[2];
      read(STDIN_FILENO, &seq[0], 1);
      read(STDIN_FILENO, &seq[1], 1);
      if (seq[0] == '[') {
        if (seq[1] == 'C') { // →
          cursor_col = moveCursorRight(buffer[0], cursor_col);
        } else if (seq[1] == 'D') { // ←
          cursor_col = moveCursorLeft(buffer[0], cursor_col);
        }
      }
    } else {
      buffer[0].insert(cursor_col, 1, c);
      cursor_col++;
      applyReplacement(buffer[0], cursor_col);
    }

    std::string output = prompt;
    int idx = 0;
    while (idx < (int)buffer[0].size()) {
      int char_end = moveCursorRight(buffer[0], idx);
      std::string utf8_char = buffer[0].substr(idx, char_end - idx);

      if (idx == cursor_col) {
        output += REVERSE_ON + utf8_char + REVERSE_OFF;
      } else {
        output += utf8_char;
      }

      idx = char_end;
    }
    if (cursor_col >= (int)buffer[0].size()) {
      output += REVERSE_ON " " REVERSE_OFF;
    }

    std::cout << "\r\033[2K" << output << std::flush;
  }
}
