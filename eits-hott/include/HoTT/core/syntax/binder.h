// include/EITS/kernel/syntax/binder.h

#pragma once

#include "HoTT/core/syntax/expression/expression.h"

namespace EITS {

struct Binder {
	std::string name;
	Expression type;

	Binder(std::string _name, Expression _type) : name(_name), type(_type) {};

	void dump();
	std::string to_string() const;
	void print(std::ostream &os = std::cout) const;
};

} // namespace EITS
