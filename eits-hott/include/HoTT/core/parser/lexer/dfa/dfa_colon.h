#pragma once

#include "HoTT/core/parser/lexer/dfa/dfa_base.h"

namespace EITS {

struct DFAColon : DFA {
	enum class State {
		START,
		DONE,
		ERROR,
	};

	State state;
	bool accepted;

	void reset() override;
	DFAResultType feed(char32_t ch) override;
	bool isAccepting() const override;
};

} // namespace EITS
