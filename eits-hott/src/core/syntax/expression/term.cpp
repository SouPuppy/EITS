// src/kernel/syntax/expression/term.h

#include "HoTT/core/syntax/expression/term.h"

#include <iostream>

namespace EITS {

void Term::dump() {
	std::cout << "[Term]" << std::endl;
}

std::string Term::to_string() const {
	return "[Term]";
}

void Term::print(std::ostream& os) const {
	os << to_string();
}

} // namespace EITS
