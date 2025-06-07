// include/Machinish/kernel/syntax/expression/expression.h

#pragma once

#include <memory>
#include <variant>

#include "term.h"
#include "type.h"
#include "universe.h"
#include "variable.h"

namespace Machinish {

using ExpressionVariant = std::variant<
	std::shared_ptr<Term>,
	std::shared_ptr<Type>,
	std::shared_ptr<Universe>,
	std::shared_ptr<Variable>
>;

struct Expression : ExpressionVariant, ExpressionTemplate {
	virtual ~Expression() = default;
	using ExpressionVariant::ExpressionVariant;
	
	void dump() override;
	std::string to_string() const override;
	void print(std::ostream &os = std::cout) const override;
};

// using ExpressionPtr = std::shared_ptr<Expression>;

} // namespace Machinish
