// include/Machinish/kernel/syntax/expression/expression.h

#pragma once

#include <memory>
#include <variant>

#include "expression_template.h"
#include "term.h"
#include "type.h"
#include "universe.h"
#include "variable.h"

namespace Machinish {

using ExpressionVariant = std::variant<Term, Type, Universe, Variable>;

struct Expression : ExpressionVariant, ExpressionTemplate {
	virtual ~Expression() = default;
	using ExpressionVariant::ExpressionVariant;
	
	void dump() override;
	std::string to_string() const override;
	void print(std::ostream &os = std::cout) const override;
};

using ExpressionPtr = std::shared_ptr<Expression>;

} // namespace Machinish
