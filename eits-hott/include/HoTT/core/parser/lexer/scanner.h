#pragma once

#include <cstddef>
#include <string>
namespace EITS {

struct Scanner {
	std::u32string buffer;
  size_t pos = 0;
  int line = 1;

	explicit Scanner(const std::string& input);

	void skipWhitespace();

	char32_t peek() const;
	char32_t advance();
  bool isAtEnd() const;

	int getLine() const { return line; }
	size_t getPostion() const { return pos; }
};

} // namespace EITS
