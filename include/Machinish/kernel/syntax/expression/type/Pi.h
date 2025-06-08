// include/Machinish/kernel/syntax/expression/type/Pi.h

#pragma once

#include "Machinish/kernel/syntax/expression/type.h"
#include "Machinish/kernel/syntax/binder.h"
#include "Machinish/kernel/syntax/expression/expression.h"

namespace Machinish {

struct Pi : Type {
  Binder binder;
  Expression codomain;

	//NOTE - Add anonymous Pi constructor
	// Pi(Expression binder, Expression domain, Expression codomain, Level level = Level::zero())
	// 	: Type(level), binder(binder), domain(domain), codomain(codomain) {}

	Pi(Binder binder, Expression codomain, Level level = Level::zero())
		: Type(level), binder(binder), codomain(codomain) {}
	
	~Pi() override = default;
	void dump() override;
	std::string to_string() const override;
	void print(std::ostream& os = std::cout) const override;
};

} // namespace Machinish
