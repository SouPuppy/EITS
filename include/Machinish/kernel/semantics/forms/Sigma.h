// include/Machinish/kernel/semantics/forms/Sigma.h

#pragma once

#include "Machinish/kernel/syntax/binder.h"
#include "Machinish/kernel/syntax/expression/expression.h"

namespace Machinish {

struct Sigma : ExpressionTemplate {
	Binder binder;
	ExpressionPtr body;
};

} // namespace Machinish
