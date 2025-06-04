// src/kernel/runtime/context.cpp

#include "Machinish/kernel/runtime/context.h"

#include <optional>
#include <iostream>
#include <utility>

namespace Machinish {

void Context::add(const std::string& name, ExpressionPtr expr) {
	entries.emplace_back(std::make_pair(name, expr));
}

void Context::show(std::ostream& os) const {
	for (const auto& [name, expr] : entries) {
		os << name << " : ";
		if (expr) expr->print(os);
		else os << "<null>";
		os << "\n";
	}
}

std::optional<ExpressionPtr> Context::lookup(const std::string& name) const {
	for (auto it = entries.rbegin(); it != entries.rend(); ++it) {
		if (it->first == name) {
			return it->second;
		}
	}
	return std::nullopt;
}

} // namespace Machinish
