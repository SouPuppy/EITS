// include/Machinish/kernel/runtime/context.h

#pragma once

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <optional>

#include <Machinish/kernel/syntax/expression/expression.h>
namespace Machinish {

struct Context {
	std::vector<std::pair<std::string, ExpressionPtr>> entries;
	
	~Context() = default;
	void add(const std::string& name, ExpressionPtr expr);
	void show(std::ostream& os = std::cout) const;
	std::optional<ExpressionPtr> lookup(const std::string& name) const;
};

} // namespace Machinish
