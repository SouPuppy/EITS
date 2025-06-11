#include "HoTT/core/parser/lexer/dfa/dfa_base.h"
#include "HoTT/core/parser/lexer/dfa/dfa_colon.h"

namespace EITS {

void DFAColon::reset() { accepted = false; }

DFAResultType DFAColon::feed(char32_t ch) {
	if (!accepted && ch == U':') {
		accepted = true;
		buffer = U":";
		return DFAResultType::ACCEPT;
	}
	return DFAResultType::ERROR;
}

bool DFAColon::isAccepting() const { return accepted; }

} // namespace EITS
