// src/kernel/syntax/expression/type/Pi.h

#include <iostream>

#include "HoTT/core/syntax/expression/type/Pi.h"

namespace EITS {

void Pi::dump() {
  std::cout << "[Pi] (";
  binder.print();
  std::cout << ") → ";
  codomain.print();
  std::cout << std::endl;
}

std::string Pi::to_string() const {
  return "Π(" + binder.to_string() + ") → " + codomain.to_string();
}

void Pi::print(std::ostream &os) const { os << to_string(); }

} // namespace EITS
