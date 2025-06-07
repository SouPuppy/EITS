// include/Machinish/kernel/syntax/binder.h

#pragma once

#include "Machinish/kernel/syntax/expression/expression.h"

namespace Machinish {

struct Binder {
	std::string name;
	ExpressionPtr type;

	Binder(std::string _name, ExpressionPtr _type) : name(_name), type(_type) {};

	void dump();
	std::string to_string() const;
	void print(std::ostream &os = std::cout) const;
};

} // namespace Machinish
