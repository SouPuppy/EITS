#pragma once

#include <string>

namespace EITS {

enum class TokenType {
	IDENTIFIER,
	NUMBER,

	// Keywords
	TYPE,
	NATURAL_NUMBER_TYPE,

	// Symbols
	COLON,         // :
	COMMA,         // ,
	LPAREN,        // (
	RPAREN,        // )
	ARROW,         // →
	FORALL,        // ∀

	// Special
	EOF_TOKEN,
	INVALID_TOKEN,
};

inline std::string to_string(TokenType t) {
	switch (t) {
		case TokenType::IDENTIFIER:     				return "IDENTIFIER";
		case TokenType::NUMBER:         				return "NUMBER";
		case TokenType::TYPE:           				return "KEYWORD_Type";
		case TokenType::NATURAL_NUMBER_TYPE:		return "KEYWORD_ℕ";
		case TokenType::COLON:          				return "COLON";
		case TokenType::COMMA:          				return "COMMA";
		case TokenType::LPAREN:         				return "LPAREN";
		case TokenType::RPAREN:         				return "RPAREN";
		case TokenType::ARROW:          				return "ARROW";
		case TokenType::FORALL:         				return "FORALL";
		case TokenType::EOF_TOKEN:      				return "EOF";
		case TokenType::INVALID_TOKEN:  				return "INVALID";
		default:                        				return "UNKNOWN";
	}
}

struct Token {
	TokenType type;
	std::u32string lexme;  // View into source buffer
	int line, column;

	Token(TokenType type, std::u32string lexme, int line, int column);
	void dump() const;
};

} // namespace EITS
