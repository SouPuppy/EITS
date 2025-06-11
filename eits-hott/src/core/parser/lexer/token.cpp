#include "HoTT/core/parser/lexer/token.h"

#include <iostream>
#include <string_view>
#include "utf8_decoder.h"

namespace EITS {

Token::Token(TokenType type, std::u32string lexme, int line)
	: type(type), lexme(lexme), line(line) {}

void Token::dump() const {
	std::cout << "[" << to_string(type) << "] "
		<< "\"" << to_utf8(lexme) << "\""
		<< " @ line " << line << "\n";
}

} // namespace EITS
