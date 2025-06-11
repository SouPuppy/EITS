#include "HoTT/core/parser/lexer/dfa/dfa_base.h"
#include "HoTT/core/parser/lexer/dfa/dfa_number.h"
#include "charutil.h"
namespace EITS {

void DFANumber::reset() { state = State::START; buffer.clear(); accepting = false; }

DFAResultType DFANumber::feed(char32_t ch) {
	switch (state) {
		case State::START:
			if (CharUtil::isDigit(ch)) {
				state = State::INTEGER;
				buffer += ch;
				accepting = true;
				return DFAResultType::CONTINUE;
			}
			return DFAResultType::ERROR;
		case State::INTEGER:
			if (CharUtil::isDigit(ch)) {
				buffer += ch;
				accepting = true;
				return DFAResultType::CONTINUE;
			}
			return DFAResultType::ACCEPT;
		default: return DFAResultType::ERROR;
	}
}

bool DFANumber::isAccepting() const { return accepting; }

} // namespace EITS
