// include/Machinish/kernel/syntax/expression/term.h

#pragma once

#include "Machinish/kernel/syntax/expression/expression.h"

namespace Machinish {

struct Term : Expression {
	void dump() override;
	std::string to_string() const override;
	void print(std::ostream& os = std::cout) const override;
};

} // namespace Machinish
