#pragma once

#include <string>
namespace EITS {

enum class TokenType {
	IDENTIFIER,
	NUMBER,

	// Keywords
	TYPE,
	
	COLON,
	
	EOF_TOKEN,
	INVALID_TOKEN,
};

inline const char* to_string(TokenType t) {
  switch (t) {
		case TokenType::IDENTIFIER:  		return "IDENTIFIER";
		case TokenType::NUMBER:       		return "NUMBER";
		case TokenType::TYPE:        		return "TYPE";
		case TokenType::COLON:       		return "COLON";
		case TokenType::EOF_TOKEN:   		return "EOF";
		case TokenType::INVALID_TOKEN: 	return "INVALID";
		default:                     		return "UNKNOWN";
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
