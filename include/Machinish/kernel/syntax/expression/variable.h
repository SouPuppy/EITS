// include/Machinish/kernel/syntax/expression/type.h

#pragma once

#include "Machinish/kernel/syntax/expression/expression_template.h"

namespace Machinish {

struct Variable : ExpressionTemplate {
	virtual ~Variable() = default;
	void dump() override;
	std::string to_string() const override;
	void print(std::ostream& os = std::cout) const override;
};

} // namespace Machinish
