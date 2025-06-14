#include "HoTT/core/parser/lexer/stratagy/base_stratagy.h"
#include "HoTT/core/parser/lexer/stratagy_manager.h"

#include "HoTT/core/parser/lexer/stratagy/identifier_stratagy.h"
#include "HoTT/core/parser/lexer/stratagy/number_stratagy.h"


#include "HoTT/core/parser/lexer/token.h"
#include <optional>
#include <memory>
#include "HoTT/core/parser/lexer/scanner.h"
#include <vector>

namespace EITS {

TokenType StrategyManager::resolveTokenType(const std::unique_ptr<LexerStrategy> &strat) {
  if (dynamic_cast<IdentifierStrategy *>(strat.get())) {
    return TokenType::IDENTIFIER;
  }
	if (dynamic_cast<NumberStrategy *>(strat.get())) {
    return TokenType::NUMBER;
  }
  return TokenType::INVALID_TOKEN;
}

StrategyManager::StrategyManager() {
  strategies.push_back(std::make_unique<IdentifierStrategy>());
  strategies.push_back(std::make_unique<NumberStrategy>());
}

std::optional<std::pair<TokenType, std::u32string>> StrategyManager::tryAll(Scanner &scanner) {
  for (auto &strat : strategies) {
    strat->reset();
    char32_t c;
    DFAResultType res;

    while (!scanner.isAtEnd()) {
      c = scanner.peek(strat->getLexeme().size());
      res = strat->feed(c);
      if (res == DFAResultType::CONTINUE) {
      } else if (res == DFAResultType::ACCEPT) {
        break;
      } else {
        break;
      }
    }

    if (!strat->getLexeme().empty() && res == DFAResultType::ACCEPT) {
      return std::make_pair(resolveTokenType(strat), strat->getLexeme());
    }
  }
  return std::nullopt;
}

}; // namespace EITS
