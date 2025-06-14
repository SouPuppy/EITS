#include "HoTT/core/parser/lexer/token.h"

#include <iostream>
#include <iomanip>

#include "utf8_decoder.h"

namespace EITS {

Token::Token(TokenType type, std::u32string lexme, int line, int column)
	: type(type), lexme(lexme), line(line), column(column) {}

void Token::dump() const {
	std::cout << std::left
					  << std::setw(16) << to_string(type)
						<< std::setw(18) << to_utf8(lexme)
						<< " @ [" << std::setw(5) << line
						<< ", " << column << std::setw(5) << "]"
						<< "\n";
}

} // namespace EITS
