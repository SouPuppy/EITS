#pragma once

#include "HoTT/core/parser/lexer/stratagy/base_stratagy.h"
#include "HoTT/core/parser/lexer/token.h"
#include <optional>
#include <memory>
#include "HoTT/core/parser/lexer/scanner.h"
#include <vector>

namespace EITS {

struct StrategyManager {
	std::vector<std::unique_ptr<LexerStrategy>> strategies;

	StrategyManager();
	std::optional<std::pair<TokenType, std::u32string>> tryAll(Scanner& scanner);
  TokenType resolveTokenType(const std::unique_ptr<LexerStrategy>& strat);
};


}; // namespace EITS
