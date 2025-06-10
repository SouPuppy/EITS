#pragma once

#include <string>
#include <vector>
#include <optional>

// Launch the terminal-based multi-line editor.
// Returns user input as a list of strings, one for each line.
std::optional<std::string> launchSingleLineEditor(int prompt_id = 0);
std::optional<std::vector<std::string>> launchEditor();
