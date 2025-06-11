#pragma once

#include <string>

namespace EITS {

enum DFAResultType {
	ACCEPT,
	CONTINUE,
	ERROR,
};

struct DFA {
	std::u32string buffer;
	virtual void reset() = 0;
	virtual DFAResultType feed(char32_t ch) = 0;
	virtual bool isAccepting() const = 0;
	std::u32string getLexeme() const { return buffer; }
	virtual ~DFA() = default;
};

}; // namespace EITS
