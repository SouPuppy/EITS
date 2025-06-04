// src/kernel/syntax/expression/type.h

#include "Machinish/kernel/syntax/expression/type.h"

#include <iostream>

namespace Machinish {

void Type::dump() {
	std::cout << "[Type] - dump()" << std::endl;
}

std::string Type::to_string() const {
	return "[Type]";
}

void Type::print(std::ostream& os) const {
	os << to_string();
}

} // namespace Machinish
