#pragma once

#include "HoTT/core/parser/lexer/dfa/dfa_base.h"

namespace EITS {

struct DFANumber : DFA {
	enum class State {
		START,
		INTEGER,
		DONE,
		ERROR,
	};

	State state;
	bool accepting;

	void reset() override;
	DFAResultType feed(char32_t ch) override;
	bool isAccepting() const override;
};

} // namespace EITS
