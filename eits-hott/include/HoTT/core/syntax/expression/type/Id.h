// include/EITS/kernel/syntax/expression/type/Id.h

#pragma once

#include "HoTT/core/syntax/expression/type.h"
#include "HoTT/core/syntax/expression/expression.h"

namespace EITS {

struct Id : Type {
	Expression base;
	Expression endpoint[2];

	~Id() override = default;
	Id(Expression _base, Expression lhs, Expression rhs)
		: base(_base) {
		endpoint[0] = lhs;
		endpoint[1] = rhs;
	}

	inline Expression lhs() const { return endpoint[0]; }
	inline Expression rhs() const { return endpoint[1]; }

	void dump() override;
	std::string to_string() const override;
	void print(std::ostream& os = std::cout) const override;
};

} // namespace EITS
