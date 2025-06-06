// include/Machinish/kernel/semantics/forms/Pi.h

#pragma once

#include "Machinish/kernel/syntax/expression/expression.h"
#include "Machinish/kernel/syntax/binder.h"

namespace Machinish {

struct Pi : Expression {
	Binder binder;
	ExpressionPtr body;

	Pi(Binder _binder, ExpressionPtr _body)
		: binder(_binder), body(_body) {};
	void dump() override;
	std::string to_string() const override;
	void print(std::ostream& os = std::cout) const override;
};

} // namesapce Machinish
