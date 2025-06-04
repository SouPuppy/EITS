// src/kernel/syntax/expression/term.h

#include "Machinish/kernel/syntax/expression/term.h"

#include <iostream>

namespace Machinish {

void Term::dump() {
	std::cout << "[Term] - dump()" << std::endl;
}

std::string Term::to_string() const {
	return "[Term]";
}

void Term::print(std::ostream& os) const {
	os << to_string();
}

} // namespace Machinish
