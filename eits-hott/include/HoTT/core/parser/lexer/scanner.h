#pragma once

#include <cstddef>
#include <string>
namespace EITS {

struct Scanner {
	std::u32string buffer;
  size_t pos = 0;
  int line = 1, column = 1;

	explicit Scanner(const std::string& input);

	void skipWhitespace();

	char32_t peek(size_t offset = 0) const;
	char32_t advance();
	void consume(size_t count);
  bool isAtEnd() const;

	int getLine() const { return line; }
	int getColumn() const { return column; }
	size_t getPostion() const { return pos; }
};

} // namespace EITS
