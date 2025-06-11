#pragma once

#include <string>
#include <unordered_map>
#include "HoTT/core/parser/lexer/token.h"

namespace EITS::Lexer {

// Simple keyword lookup table
inline const std::unordered_map<std::u32string, TokenType> keywordTable = {
	{U"def", TokenType::DEF},
	{U"Type", TokenType::TYPE}
};

// Fallback to IDENTIFIER if not keyword
inline TokenType matchKeywordOrIdentifier(const std::u32string& word) {
	auto it = keywordTable.find(word);
	if (it != keywordTable.end()) return it->second;
	return TokenType::IDENTIFIER;
}

}
