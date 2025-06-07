// include/Machinish/kernel/syntax/expression/expression.h

#pragma once

#include <variant>

#include "term.h"
#include "type.h"
#include "universe.h"
#include "variable.h"

namespace Machinish {

using ExpressionVariant = std::variant<Term, Type, Universe, Variable>;

struct Expression : ExpressionVariant {
	using ExpressionVariant::ExpressionVariant;

	std::string to_string() const;
};

} // namespace Machinish
