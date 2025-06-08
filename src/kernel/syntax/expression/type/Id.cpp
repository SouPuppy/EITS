// src/kernel/syntax/expression/type/Id.h

#include <iostream>

#include "Machinish/kernel/syntax/expression/type/Id.h"

namespace Machinish {

void Id::dump() {
	std::cout << "[Id] Id ";
	base.print(); std::cout << " ";
	lhs().print(); std::cout << " ";
	rhs().print(); std::cout << "\n";
}

std::string Id::to_string() const {
	return "Id " + base.to_string() + " " + lhs().to_string() + " " + rhs().to_string();
}

void Id::print(std::ostream &os) const { os << to_string(); }

} // namespace Machinish
