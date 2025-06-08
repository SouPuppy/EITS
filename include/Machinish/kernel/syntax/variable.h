// include/Machinish/kernel/syntax/variable.h

#pragma once

#include "Machinish/kernel/syntax/expression/expression.h"

namespace Machinish {

struct Variable {
	std::string name;
	Expression type;

	Variable(std::string _name, Expression _type) : name(_name), type(_type) {};

	void dump();
	std::string to_string() const;
	void print(std::ostream &os = std::cout) const;
};

} // namespace Machinish
