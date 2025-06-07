// src/kerne/syntax/binder.cpp

#include "Machinish/kernel/syntax/binder.h"

namespace Machinish {

// Binder::Binder(ExpressionPtr _name, ExpressionPtr _type)
// 	: name(_name), type(_type) {};

void Binder::dump() {
  std::cout << "[Bind]" << std::endl;
  std::cout << " - " << "name: '" << name << "'" << std::endl;
  std::cout << " - " << "type: " << type.to_string() << std::endl;
}

std::string Binder::to_string() const {
  return name + " : " + type.to_string();
}

void Binder::print(std::ostream &os) const { os << to_string(); }

} // namespace Machinish
