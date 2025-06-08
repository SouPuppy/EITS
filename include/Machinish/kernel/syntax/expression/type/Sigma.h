// include/Machinish/kernel/syntax/expression/type/Sigma.h

#pragma once

#include "Machinish/kernel/syntax/expression/type.h"
#include "Machinish/kernel/syntax/binder.h"
#include "Machinish/kernel/syntax/expression/expression.h"

namespace Machinish {

struct Sigma : Type {
  Binder binder;
  Expression codomain;

	//NOTE - Add anonymous Sigma constructor
	// Sigma(Expression binder, Expression domain, Expression codomain, Level level = Level::zero())
	// 	: Type(level), binder(binder), domain(domain), codomain(codomain) {}

	Sigma(Binder binder, Expression codomain, Level level = Level::zero())
		: Type(level), binder(binder), codomain(codomain) {}
	
	~Sigma() override = default;
	void dump() override;
	std::string to_string() const override;
	void print(std::ostream& os = std::cout) const override;
};

} // namespace Machinish
