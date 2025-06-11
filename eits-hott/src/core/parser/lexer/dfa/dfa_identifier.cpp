#include "HoTT/core/parser/lexer/dfa/dfa_base.h"
#include "HoTT/core/parser/lexer/dfa/dfa_identifier.h"
#include "charutil.h"

namespace EITS {

void DFAIdentifier::reset() { state = State::START; accepting = false; }

DFAResultType DFAIdentifier::feed(char32_t ch) {
	switch (state) {
		case State::START:
			if (CharUtil::isAlpha(ch)) {
				state = State::BODY;
				accepting = true;
				return DFAResultType::CONTINUE;
			}
			return DFAResultType::NONE;
		case State::BODY:
			if (CharUtil::isAlpha(ch)) {
				accepting = true;
				return DFAResultType::CONTINUE;
			}
			return DFAResultType::ACCEPT;
		default: return DFAResultType::ERROR;
	}
	return DFAResultType::ERROR;
}

bool DFAIdentifier::isAccepting() const { return accepting; }

} // namespace EITS
