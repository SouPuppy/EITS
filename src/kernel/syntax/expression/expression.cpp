// src/kernel/syntax/expression.cpp

#include "Machinish/kernel/syntax/expression/expression.h"

namespace Machinish {

std::string Expression::to_string() const {
	return std::visit([](auto &&arg) { return arg.to_string(); }, *this);
}

} // namespace Machinish
