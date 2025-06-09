// src/kernel/syntax/expression/type.h

#include "HoTT/core/syntax/expression/type.h"
#include "HoTT/core/basis/level.h"

#include <iostream>

namespace EITS {

void Type::dump() {
	std::cout << "[Type]" << std::endl;
}

std::string Type::to_string() const {
	return "Type " + level.to_string();
}

void Type::print(std::ostream& os) const {
	os << to_string();
}

} // namespace EITS
