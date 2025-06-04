// include/Machinish/kernel/syntax/expression

#include <memory>
#include <iostream>

namespace Machinish {

struct Expression {
	~Expression() = default;
	virtual void print(std::ostream& os = std::cout) const = 0;
};

using ExpressionPtr = std::shared_ptr<Expression>;

} // namespace Machinish
