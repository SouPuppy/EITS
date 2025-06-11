#pragma once

#include <cstddef>
#include <string>

namespace EITS {

enum DFAResultType {
	NONE,
	ACCEPT,
	CONTINUE,
	ERROR,
};

struct DFA {
	virtual void reset() = 0;
	virtual DFAResultType feed(char32_t ch) = 0;
	virtual bool isAccepting() const = 0;
	virtual ~DFA() = default;
};

}; // namespace EITS
