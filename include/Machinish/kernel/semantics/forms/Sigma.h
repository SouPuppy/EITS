// include/Machinish/kernel/semantics/forms/Sigma.h

#pragma once

#include "Machinish/kernel/syntax/expression/expression.h"
#include "Machinish/kernel/syntax/binder.h"

namespace Machinish {

struct Sigma : ExpressionTemplate {
	Binder binder;
	ExpressionPtr body;
};

} // namesapce Machinish
