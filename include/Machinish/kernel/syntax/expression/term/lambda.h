// include/Machinish/kernel/semantics/constructor/lambda.h

#pragma once

#include "Machinish/kernel/syntax/binder.h"
#include "Machinish/kernel/syntax/expression/expression.h"
#include "variable.h"


namespace Machinish {

// Pi Lamdba(Variable binder, Expression codmain);

// // Pi x:A -> B

struct Lambda : Term {
	Binder bind;
	
};

} // namespace Machinish
