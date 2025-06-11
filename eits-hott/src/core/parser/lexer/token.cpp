#include "HoTT/core/parser/lexer/token.h"

#include <iostream>
#include <iomanip>

#include "utf8_decoder.h"

namespace EITS {

Token::Token(TokenType type, std::u32string lexme, int line, int column)
	: type(type), lexme(lexme), line(line), column(column) {}

void Token::dump() const {
	std::cout << std::left
					  << std::setw(12) << to_string(type)
						<< std::setw(16) << to_utf8(lexme)
						<< " @ [" << std::setw(3) << line
						<< ", " << column << std::setw(3) << "]"
						<< "\n";
}


} // namespace EITS
