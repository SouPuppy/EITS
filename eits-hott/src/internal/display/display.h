#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <locale>
#include <codecvt>
#include <wchar.h>

namespace EITS::display {

// ANSI sequences for underline
inline constexpr const char* ANSI_UNDERLINE_ON  = "\033[4m";
inline constexpr const char* ANSI_UNDERLINE_OFF = "\033[24m";

// Remove ANSI escape codes from string
inline std::string strip_ansi(const std::string& str) {
	static const std::regex ansi_escape("\033\\[[0-9;]*m");
	return std::regex_replace(str, ansi_escape, "");
}

// Compute visual width (ignoring ANSI, handling Unicode)
inline size_t visual_width(const std::string& str) {
	std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
	std::wstring wstr = conv.from_bytes(strip_ansi(str));

	size_t width = 0;
	for (wchar_t ch : wstr) {
		int w = wcwidth(ch);
		width += (w > 0) ? w : 0;
	}
	return width;
}

// Center-align string in given width
inline std::string center(const std::string& str, size_t width) {
	size_t vis_len = visual_width(str);
	if (vis_len >= width) return str;
	size_t pad_left = (width - vis_len) / 2;
	size_t pad_right = width - vis_len - pad_left;
	return std::string(pad_left, ' ') + str + std::string(pad_right, ' ');
}

// Join premise strings with 4-space separation
inline std::string join_premises(const std::vector<std::string>& premises) {
	std::string result;
	for (size_t i = 0; i < premises.size(); ++i) {
		result += premises[i];
		if (i + 1 < premises.size()) result += "    ";
	}
	return result;
}

// Pretty-print inference rule with ANSI underline
inline void display_inference(const std::vector<std::string>& premises, const std::string& conclusion) {
	std::string joined = join_premises(premises);
	size_t maxLen = std::max(visual_width(joined), visual_width(conclusion));

	std::cout << center(ANSI_UNDERLINE_ON + joined + ANSI_UNDERLINE_OFF, maxLen) << "\n";
	std::cout << center(conclusion, maxLen) << "\n";
}

// Support initializer_list input
inline void display_inference(std::initializer_list<std::string> premises, const std::string& conclusion) {
	display_inference(std::vector<std::string>(premises), conclusion);
}

} // namespace EITS::display
