#pragma once

#include <string>
#include <unordered_map>
#include "HoTT/core/parser/lexer/token.h"
#include "HoTT/core/parser/lexer/dfa/dfa_base.h"

namespace EITS {

struct DFAIdentifier : DFA {
	enum class State {
		START,
		BODY,
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
