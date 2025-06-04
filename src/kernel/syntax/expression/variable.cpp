// src/kernel/syntax/expression/variable.h

#include "Machinish/kernel/syntax/expression/variable.h"

#include <iostream>

namespace Machinish {

void Variable::dump() {
	std::cout << "[Variable] - dump()" << std::endl;
}

std::string Variable::to_string() const {
	return "[Variable]";
}

void Variable::print(std::ostream& os) const {
	os << to_string();
}

} // namespace Machinish
