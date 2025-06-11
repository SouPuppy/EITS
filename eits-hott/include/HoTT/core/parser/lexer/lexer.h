#pragma oance

#include "HoTT/core/parser/lexer/scanner.h"

#include <vector>

#include <string>
#include "HoTT/core/parser/lexer/token.h"

#include "HoTT/core/parser/lexer/dfa/dfa_identifier.h"

#include "HoTT/core/parser/lexer/scanner.h"

namespace EITS {

struct Lexer {
	std::u32string source;
	Scanner scanner;
	size_t start = 0;
  size_t current = 0;
  int line = 1;

	DFAIdentifier idDFA;
	
	explicit Lexer(const std::string& src);
	Token nextToken();
	std::vector<Token> all();
};

} // namespace EITS
