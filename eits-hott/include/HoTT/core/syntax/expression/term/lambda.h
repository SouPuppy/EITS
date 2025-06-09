// include/EITS/kernel/semantics/constructor/lambda.h

#pragma once

#include "HoTT/core/syntax/binder.h"
#include "HoTT/core/syntax/expression/expression.h"
#include "variable.h"


namespace EITS {

// Pi Lamdba(Variable binder, Expression codmain);

// // Pi x:A -> B

struct Lambda : Term {
	Binder bind;
	
};

} // namespace EITS
