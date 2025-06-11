#pragma once

#include <string>

inline std::string to_utf8(std::u32string_view sv) {
	std::string result;
	for (char32_t cp : sv) {
		if (cp <= 0x7F) {
			result += static_cast<char>(cp);
		} else if (cp <= 0x7FF) {
			result += static_cast<char>(0xC0 | ((cp >> 6) & 0x1F));
			result += static_cast<char>(0x80 | (cp & 0x3F));
		} else if (cp <= 0xFFFF) {
			result += static_cast<char>(0xE0 | ((cp >> 12) & 0x0F));
			result += static_cast<char>(0x80 | ((cp >> 6) & 0x3F));
			result += static_cast<char>(0x80 | (cp & 0x3F));
		} else if (cp <= 0x10FFFF) {
			result += static_cast<char>(0xF0 | ((cp >> 18) & 0x07));
			result += static_cast<char>(0x80 | ((cp >> 12) & 0x3F));
			result += static_cast<char>(0x80 | ((cp >> 6) & 0x3F));
			result += static_cast<char>(0x80 | (cp & 0x3F));
		} else {
			// Invalid Unicode code point, skip or use replacement char
			result += '?';
		}
	}
	return result;
}

inline std::u32string decode_utf8(const std::string& input) {
	std::u32string result;
	size_t i = 0;
	while (i < input.size()) {
		unsigned char byte = static_cast<unsigned char>(input[i]);
		char32_t codepoint = 0;
		size_t extra = 0;

		if (byte <= 0x7F) {
			codepoint = byte;
			extra = 0;
		} else if ((byte & 0xE0) == 0xC0) {
			codepoint = byte & 0x1F;
			extra = 1;
			if (codepoint < 0x2) goto invalid; // overlong
		} else if ((byte & 0xF0) == 0xE0) {
			codepoint = byte & 0x0F;
			extra = 2;
		} else if ((byte & 0xF8) == 0xF0) {
			codepoint = byte & 0x07;
			extra = 3;
			if (codepoint > 0x10) goto invalid;
		} else {
			goto invalid;
		}

		if (i + extra >= input.size()) goto invalid;

		for (size_t j = 1; j <= extra; ++j) {
			unsigned char cc = static_cast<unsigned char>(input[i + j]);
			if ((cc & 0xC0) != 0x80) goto invalid;
			codepoint = (codepoint << 6) | (cc & 0x3F);
		}

		if ((codepoint >= 0xD800 && codepoint <= 0xDFFF) || codepoint > 0x10FFFF)
			goto invalid;

		result.push_back(codepoint);
		i += extra + 1;
		continue;

	invalid:
		result.push_back(U'?');
		++i;
	}
	return result;
}
