// include/Machinish/kernel/syntax/expression/expression.h

#pragma once

#include <memory>
#include <iostream>

namespace Machinish {

struct Expression {
	~Expression() = default;
	virtual void dump() = 0;
	virtual std::string to_string() const = 0;
	virtual void print(std::ostream& os = std::cout) const = 0;
};

using ExpressionPtr = std::shared_ptr<Expression>;

} // namespace Machinish
