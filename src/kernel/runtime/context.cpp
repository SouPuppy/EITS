// src/kernel/runtime/context.cpp

#include "Machinish/kernel/semantics/context.h"

#include <optional>
#include <iostream>
#include <utility>

namespace Machinish {

void Context::clear() {
	entries.clear();
}

void Context::add(const std::string& name, ExpressionPtr expr) {
	entries.emplace_back(std::make_pair(name, expr));
}

void Context::dump(std::ostream& os) const {
	os << "Γ := {";
	os << ("\n "[entries.empty()]);
	for (const auto& [name, expr] : entries) {
		os << "  " << name << " ↦ ";
		if (expr) expr->print(os); 
		else os << "<null>";
		os << "\n";
	}
	os << "}\n";
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
