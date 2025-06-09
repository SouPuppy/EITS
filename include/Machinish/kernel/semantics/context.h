// include/Machinish/kernel/semantics/context.h

#pragma once

#include <optional>
#include <string>
#include <unordered_map>

#include <Machinish/kernel/syntax/expression/type.h>

namespace Machinish {

struct Context {
	std::shared_ptr<Context> parent;
	std::unordered_map<std::string, std::shared_ptr<Type>> gamma;
	int depth = 0;

	~Context() = default;
	void clear();
	int add(const std::string &name, std::shared_ptr<Type> type);
	void extend();
	std::optional<std::shared_ptr<Type>> lookup(const std::string &name) const;
	void dump(std::ostream& os = std::cout) const;
};

} // namespace Machinish
