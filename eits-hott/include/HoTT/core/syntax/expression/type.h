// include/EITS/kernel/syntax/expression/type.h

#pragma once

#include "HoTT/core/basis/level.h"
#include "internal/expression/expression_template.h"

namespace EITS {

struct Type : ExpressionTemplate {
	Level level;
	Type() = default;
	Type(int level): level(Level(level)) {}
	Type(Level level) : level(level) {}
	virtual ~Type() = default;
	void dump() override;
	std::string to_string() const override;
	void print(std::ostream &os = std::cout) const override;
};

} // namespace EITS
