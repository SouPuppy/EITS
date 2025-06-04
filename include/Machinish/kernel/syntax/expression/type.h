// include/Machinish/kernel/syntax/expression/type.h

#pragma once

#include "Machinish/kernel/syntax/expression/expression.h"

namespace Machinish {

struct Type : Expression {
	virtual ~Type() = default;
	void dump() override;
	std::string to_string() const override;
	void print(std::ostream& os = std::cout) const override;
};

} // namespace Machinish
