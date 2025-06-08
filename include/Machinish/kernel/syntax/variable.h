// include/Machinish/kernel/syntax/variable.h

#pragma once

#include "Machinish/kernel/syntax/expression/expression.h"
#include <variant>

namespace Machinish {

struct FreeVariable {};
struct BoundVariable {
	Expression type;
	BoundVariable(Expression type);
};

using VariableVariant = std::variant<FreeVariable, BoundVariable>;

struct Variable {
	std::string name;
	VariableVariant value;

	Variable();
	Variable(std::string name);
	Variable(std::string name, Expression type);

	void dump();
	std::string to_string() const;
	void print(std::ostream& os = std::cout) const;

	bool is_free();
};

} // namespace Machinish
