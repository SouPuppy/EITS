#pragma once

#include <cstdint>

namespace EITS::CharUtil {

// Whether this Unicode scalar is a valid alphabetic char (ASCII + more)
inline bool isAlpha(char32_t ch) {
    return (ch >= U'a' && ch <= U'z') ||
           (ch >= U'A' && ch <= U'Z') ||
           (ch == U'_');
}

// Whether this is a digit (U+0030 to U+0039)
inline bool isDigit(char32_t ch) {
    return ch >= U'0' && ch <= U'9';
}

// Whitespace support (can be expanded to Unicode later)
inline bool isWhitespace(char32_t ch) {
    return ch == U' ' || ch == U'\t' || ch == U'\n' || ch == U'\r';
}

// Unicode-compliant identifier start (for now, mimic ASCII)
inline bool isIdentStart(char32_t ch) {
    return isAlpha(ch);
}

// Unicode-compliant identifier part (ASCII-based for now)
inline bool isIdentPart(char32_t ch) {
    return isAlpha(ch) || isDigit(ch);
}

} // namespace EITS::CharUtil
