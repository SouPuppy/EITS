// include/Machinish/kernel/semantics/context.h

#pragma once

#include <optional>
#include <string>
#include <unordered_map>

#include <Machinish/kernel/syntax/expression/expression.h>

namespace Machinish {

struct Context {
	std::unordered_map<std::string, Expression> entries;

	~Context() = default;
	void clear();
	int add_binding(const std::string &name, const Expression &expr);
	std::optional<Expression> lookup(const std::string &name) const;
	void dump(std::ostream& os = std::cout) const;
};

} // namespace Machinish
