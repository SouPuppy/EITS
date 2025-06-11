// include/EITS/kernel/syntax/expression/expression.h

#pragma once

#include <memory>
#include <variant>

#include "term.h"
#include "type.h"
#include "universe.h"

namespace EITS {

using ExpressionVariant = std::variant<
	std::shared_ptr<Term>,
	std::shared_ptr<Type>,
	std::shared_ptr<Universe>
>;

struct Expression : ExpressionVariant, ExpressionTemplate {
	virtual ~Expression() = default;
	using ExpressionVariant::ExpressionVariant;
	
	void dump() override;
	std::string to_string() const override;
	void print(std::ostream &os = std::cout) const override;
};

} // namespace EITS
