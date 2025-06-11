#include "HoTT/core/parser/lexer/lexer.h"
#include "HoTT/core/parser/lexer/token.h"

#include <logger.h>
#include <string>
#include <vector>
#include "utf8_decoder.h"

using namespace logger::log;

namespace EITS {

Lexer::Lexer(const std::string& src) : scanner(src) {

	source = decode_utf8(src);

	DEBUG("Lexer [string32]") << to_utf8(source);
}

Token Lexer::nextToken() {
	scanner.skipWhitespace();
	if (scanner.isAtEnd()) { return Token(TokenType::EOF_TOKEN, U"", scanner.getLine()); }
	idDFA.reset();
	std::u32string buffer;
	char32_t c = scanner.peek();
	DFAResultType res = idDFA.feed(c);

	if (res == DFAResultType::CONTINUE) {
		buffer += scanner.advance();
		while (!scanner.isAtEnd()) {
			c = scanner.peek();
			res = idDFA.feed(c);
			if (res == DFAResultType::CONTINUE) {
				buffer += scanner.advance();
			} else if (res == DFAResultType::ACCEPT) {
				break;
			} else {
				break;
			}
		}
		return Token(TokenType::IDENTIFIER, buffer, scanner.getLine());
	}

	// fallback: invalid token
	buffer += scanner.advance();
	return Token(TokenType::INVALID_TOKEN, buffer, scanner.getLine());
}

std::vector<Token> Lexer::all() {
  std::vector<Token> tokens;
	for (;;) {
		Token token = nextToken();
		tokens.push_back(token);
		if (token.type == TokenType::EOF_TOKEN) break;
		token.dump();
	}

	return tokens;
}

} // namespace EITS
