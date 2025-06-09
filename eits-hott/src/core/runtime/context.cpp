// src/kernel/runtime/context.cpp

#include "HoTT/core/semantics/context.h"

#include <optional>
#include <utility>

#include <logger.h>
using namespace logger::log;

namespace EITS {

void Context::clear() { gamma.clear(); }

int Context::add(const std::string &name, std::shared_ptr<Type> type) {
	// binding exists
	if (gamma.find(name) != gamma.end()) {
		WARNING("Variable " + name + " is already bound in the context.");
		return 1;
	}
	gamma[name] = type;
	return 0;
}

void Context::extend() {
	std::shared_ptr<Context> old = std::make_shared<Context>(*this);
	this->parent = old;
	this->gamma.clear();
	this->depth += 1;
}


std::optional<std::shared_ptr<Type>> Context::lookup(const std::string &name) const {
	std::shared_ptr<Context> p = std::make_shared<Context>(*this);
	while (p->gamma.find(name) == p->gamma.end() && p->parent != nullptr) p = p->parent;
	auto it = p->gamma.find(name);
	if (it != p->gamma.end()) {
		DEBUG("Γ ⊢ " + name + " : " + it->second->to_string());
		return it->second;
	}
	DEBUG(name + " not found");
	return std::nullopt;
}

void Context::dump(std::ostream &os) const {
	os << "Γ := {\n";
	std::shared_ptr<Context> p = std::make_shared<Context>(*this);
	while (true) {
		os << "  Scope[" << p->depth << "]:\n";
		for (const auto &it : p->gamma) {
			os << "   - " << it.first << " ↦ ";
			it.second->print(os);
			os << "\n";
		}
		if (p->parent != nullptr) p = p->parent;
		else break;
	}
	os << "}\n";
}

} // namespace EITS
