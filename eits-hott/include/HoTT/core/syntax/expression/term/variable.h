// include/EITS/kernel/syntax/variable.h

#pragma once

#include "HoTT/core/syntax/expression/expression.h"
#include "HoTT/core/syntax/expression/term.h"
#include <variant>

namespace EITS {

struct FreeVariable {};
struct BoundVariable {
	Expression type;
	BoundVariable(Expression type);
};

using VariableVariant = std::variant<FreeVariable, BoundVariable>;

struct Variable : Term {
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

} // namespace EITS
