// src/kernel/semantics/forms/Lambda.cpp

#include "Machinish/kernel/semantics/forms/Lambda.h"

#include <iostream>

namespace Machinish {

void Lambda::dump() {
	std::cout << "[Lambda] - dump()" << std::endl;
	std::cout << " - " << "binder: " << binder.to_string() << std::endl;
	std::cout << " - " << "body: " << body->to_string() << std::endl;
}

std::string Machinish::Lambda::to_string() const {
	return "λ " + binder.to_string() + ". " + body->to_string();
}

void Lambda::print(std::ostream& os) const {
	os << to_string();
}

} // namespace Machinish
