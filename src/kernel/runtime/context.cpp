// src/kernel/runtime/context.cpp

#include "Machinish/kernel/semantics/context.h"

#include <iostream>
#include <optional>
#include <utility>

#include <logger.h>
using namespace logger::log;

namespace Machinish {

void Context::clear() { entries.clear(); }

int Context::add_binding(const std::string &name, const Expression &expr) {
	// binding exists
	if (entries.find(name) != entries.end()) {
		WARNING("Variable " + name + " is already bound in the context.");
		return 1;
	}
	entries[name] = expr;
	return 0;
}

std::optional<Expression> Context::lookup(const std::string &name) const {
	const auto it = entries.find(name);
	if (it == entries.end())
		return std::nullopt;
	return it->second;
}

void Context::dump(std::ostream &os) const {
	os << "Γ := {";
	os << ("\n "[entries.empty()]);
	for (const auto &it : entries) {
		os << "  " << it.first << " ↦ ";
		it.second.print(os);
		os << "\n";
	}
	os << "}\n";
}

} // namespace Machinish
