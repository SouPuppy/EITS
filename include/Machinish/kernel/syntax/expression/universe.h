// include/Machinish/kernel/syntax/expression/type.h

#pragma once

#include "internal/expression/expression_template.h"

namespace Machinish {

struct Universe : ExpressionTemplate {
	virtual ~Universe() = default;
	void dump() override;
	std::string to_string() const override;
	void print(std::ostream &os = std::cout) const override;
};

} // namespace Machinish
