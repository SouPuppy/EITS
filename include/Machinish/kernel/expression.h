// include/Machinish/expression.h

#pragma once

#include <memory>
#include <string>

namespace Machinish {

struct Expression {
	virtual ~Expression() = default;
	virtual std::string to_string() const = 0;
};
	
using Type = std::shared_ptr<Expression>;
bool operator==(const Type &lhs, const Type &rhs);

} // namespace Machinish
