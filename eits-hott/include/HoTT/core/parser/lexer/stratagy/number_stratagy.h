#pragma once

#include "HoTT/core/parser/lexer/dfa/dfa_number.h"
#include "HoTT/core/parser/lexer/stratagy/base_stratagy.h"

namespace EITS {

class NumberStrategy : public LexerStrategy {
	DFANumber dfa;

	void reset() override { dfa.reset(); }
	DFAResultType feed(char32_t c) override { return dfa.feed(c); }
	std::u32string getLexeme() const override { return dfa.getLexeme(); }	
};

} // namespace EITS
