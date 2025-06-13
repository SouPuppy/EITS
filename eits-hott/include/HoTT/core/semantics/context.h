// include/EITS/kernel/semantics/context.h

#pragma once

#include <optional>
#include <string>
#include <unordered_map>

#include <HoTT/core/syntax/expression/expression.h>

namespace EITS {

struct Context {
	std::shared_ptr<Context> parent;
	std::unordered_map<std::string, std::shared_ptr<Expression>> gamma;
	int depth = 0;

	~Context() = default;
	void clear();
	int add(const std::string &name, std::shared_ptr<Expression> expr);
	void extend();
	std::optional<std::shared_ptr<Expression>> lookup(const std::string &name) const;
	void dump(std::ostream& os = std::cout) const;
};

} // namespace EITS
