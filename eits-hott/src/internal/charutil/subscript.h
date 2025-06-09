// src/internal/charutil/subscript.h

#pragma once

#include <string>
#include <array>

namespace EITS::charutil {

inline const std::array<std::string, 10> lower_digits = {
    "₀", "₁", "₂", "₃", "₄", "₅", "₆", "₇", "₈", "₉"
};

inline std::string subscript(int n) {
    if (n == 0) return lower_digits[0];
    std::string result;
    while (n > 0) {
        result = lower_digits[n % 10] + result;
        n /= 10;
    }
    return result;
}

inline std::string subscript(std::string str) {
	std::string result;
	for (auto &c: str) {
		if ('0' <= c && c <= '9') {
			result = result + lower_digits[c - '0'];
		}
	}
	return result;
}

} // namespace EITS::charutil
