// include/Machinish/kernel/syntax/expression/type.h

#pragma once

#include "Machinish/kernel/basis/level.h"
#include "internal/expression/expression_template.h"

namespace Machinish {

struct Type : ExpressionTemplate {
	// Level level;
	virtual ~Type() = default;
	void dump() override;
	std::string to_string() const override;
	void print(std::ostream &os = std::cout) const override;
};

} // namespace Machinish
