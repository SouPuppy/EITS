// include/Machinish/kernel/semantics/forms/Lambda.h

#pragma once

#include "Machinish/kernel/syntax/binder.h"
#include "Machinish/kernel/syntax/expression/expression.h"

namespace Machinish {

struct Lambda : ExpressionTemplate {
	Binder binder;
	ExpressionPtr body;

	Lambda(Binder _binder, ExpressionPtr _body) : binder(_binder), body(_body) {};
	void dump() override;
	std::string to_string() const override;
	void print(std::ostream &os = std::cout) const override;
};

} // namespace Machinish
