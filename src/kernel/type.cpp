// src/expression.h

#include <iostream>
#include <typeinfo>

#include <Machinish/kernel/expression.h>

namespace Machinish {

bool operator==(const Type &lhs, const Type &rhs) {
	if (!lhs || !rhs) return false;
	const Expression& lref = *lhs;
	const Expression& rref = *rhs;
	std::cout << typeid(lref).name() << "\n" << typeid(rref).name() << std::endl;
	if (typeid(lref) != typeid(rref)) {
		return false;
	}
	return true;
}

} // namespace Machinish
