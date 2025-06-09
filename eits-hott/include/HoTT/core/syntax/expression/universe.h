// include/EITS/kernel/syntax/expression/type.h

#pragma once

#include "internal/expression/expression_template.h"

namespace EITS {

struct Universe : ExpressionTemplate {
	virtual ~Universe() = default;
	void dump() override;
	std::string to_string() const override;
	void print(std::ostream &os = std::cout) const override;
};

} // namespace EITS
