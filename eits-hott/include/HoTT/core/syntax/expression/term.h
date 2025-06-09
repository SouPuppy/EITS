// include/EITS/kernel/syntax/expression/term.h

#pragma once

#include "internal/expression/expression_template.h"

namespace EITS {

struct Term : ExpressionTemplate {
	virtual ~Term() = default;
	void dump() override;
	std::string to_string() const override;
	void print(std::ostream &os = std::cout) const override;
};

} // namespace EITS
