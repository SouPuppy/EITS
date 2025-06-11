#pragma once

#include "HoTT/core/parser/lexer/dfa/dfa_base.h"

namespace EITS {

struct LexerStrategy {
	virtual void reset() = 0;
	virtual DFAResultType feed(char32_t c) = 0;
	virtual std::u32string getLexeme() const = 0;
	virtual ~LexerStrategy() = default;
};

} // namesapce EITS
