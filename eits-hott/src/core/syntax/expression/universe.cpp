// src/kernel/syntax/expression/universe.h

#include "HoTT/core/syntax/expression/universe.h"

#include <iostream>

namespace EITS {

void Universe::dump() {
	std::cout << "[Universe]" << std::endl;
}

std::string Universe::to_string() const {
	return "[Universe] 𝒰 ";
}

void Universe::print(std::ostream& os) const {
	os << to_string();
}

} // namespace EITS
