// src/kernel/semantics/forms/Pi.cpp

#include "Machinish/kernel/semantics/forms/Pi.h"

#include <iostream>

namespace Machinish {

void Pi::dump() {
	std::cout << "[Pi] - dump()" << std::endl;
	std::cout << " - " << "binder: " << binder.to_string() << std::endl;
	std::cout << " - " << "body: " << body->to_string() << std::endl;
}

std::string Machinish::Pi::to_string() const {
	return "Π " + binder.to_string() + ", " + body->to_string();
}

void Pi::print(std::ostream& os) const {
	os << to_string();
}

} // namespace Machinish
