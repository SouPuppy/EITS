#pragma oance

#include "HoTT/core/parser/lexer/dfa/dfa_identifier.h"

#include "HoTT/core/parser/lexer/scanner.h"
#include "HoTT/core/parser/lexer/token.h"
#include "HoTT/core/parser/lexer/stratagy_manager.h"

#include <string>
#include <vector>
#include "HoTT/core/parser/lexer/token.h"


namespace EITS {
	
struct Lexer {
	StrategyManager strategies;
	std::u32string source;
	Scanner scanner;

	DFAIdentifier idDFA;
	
	explicit Lexer(const std::string& src);
	Token nextToken();
	std::vector<Token> all();
};

} // namespace EITS
