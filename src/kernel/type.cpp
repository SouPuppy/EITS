// src/type.h

#include <iostream>
#include <typeinfo>

#include <Machinish/kernel/type.h>

namespace Machinish {

bool operator==(const Type &lhs, const Type &rhs) {
	if (!lhs || !rhs) return false;
	const Type_Base& lref = *lhs;
	const Type_Base& rref = *rhs;
	std::cout << typeid(lref).name() << "\n" << typeid(rref).name() << std::endl;
	if (typeid(lref) != typeid(rref)) {
		return false;
	}
	return true;
}

} // namespace Machinish
