#include "HoTT/core/parser/lexer/lexer.h"
#include "HoTT/core/parser/lexer/token.h"

#include <logger.h>
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

using namespace logger::log;

// Simple keyword lookup table
inline const std::unordered_map<std::u32string, EITS::TokenType> keywordTable = {
	{U"Type", EITS::TokenType::TYPE}
};

namespace EITS {

Lexer::Lexer(const std::string& src) : scanner(src) {}

Token Lexer::nextToken() {
	scanner.skipWhitespace();

	if (scanner.isAtEnd()) {
		return Token(TokenType::EOF_TOKEN, U"", scanner.getLine(), scanner.getColumn());
	}

	int startLine = scanner.getLine();
	int startCol = scanner.getColumn();

	// single-chracter symbols
	char32_t c = scanner.peek();
	switch (c) {
		case U':' : scanner.advance(); return Token(TokenType::COLON								,	U":", startLine, startCol);
		case U',' : scanner.advance(); return Token(TokenType::COMMA								, U",", startLine, startCol);
		case U'(' : scanner.advance(); return Token(TokenType::LPAREN								, U"(", startLine, startCol);
		case U')' : scanner.advance(); return Token(TokenType::RPAREN								, U")", startLine, startCol);
		case U'→' : scanner.advance(); return Token(TokenType::ARROW								, U"→", startLine, startCol);
		case U'∀' : scanner.advance(); return Token(TokenType::FORALL								, U"∀", startLine, startCol);
		case U'ℕ' : scanner.advance(); return Token(TokenType::NATURAL_NUMBER_TYPE	, U"ℕ", startLine, startCol);
	}

	// DFA
	auto result = strategies.tryAll(scanner);
	if (result.has_value()) {
		auto [type, lexeme] = result.value();

		if (type == TokenType::IDENTIFIER) {
			auto it = keywordTable.find(lexeme);
			if (it != keywordTable.end()) {
				type = it->second;
			}
		}

		scanner.consume(lexeme.size());
		return Token(type, lexeme, startLine, startCol);
	}

	c = scanner.advance();
	return Token(TokenType::INVALID_TOKEN, std::u32string{c}, startLine, startCol);
}


std::vector<Token> Lexer::all() {
  std::vector<Token> tokens;
	for (;;) {
		Token token = nextToken();
		tokens.push_back(token);
		if (token.type == TokenType::EOF_TOKEN) break;
	}

// Dump All
	std::cout << "TOKEN TYPE  LEXME            @ line, offset\n";
	for (auto &token: tokens) token.dump();

	return tokens;
}

} // namespace EITS
