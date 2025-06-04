// src/kernel/runtime/context.cpp

#include "Machinish/kernel/runtime/context.h"

#include <filesystem>
// #include <fstream>
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

void Context::show(std::ostream& os) const {
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

void Context::save(const std::filesystem::path& path) {
	if(path == path) {}
	std::cout << "Saving into: " << path << std::endl;
}

void Context::load(const std::filesystem::path& path) {
	if(path == path) {}
	std::cout << "Loading from: " << path << std::endl;
}

} // namespace Machinish
