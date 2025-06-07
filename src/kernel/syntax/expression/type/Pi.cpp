// src/kernel/syntax/expression/type/Pi.h

#include <iostream>

#include "Machinish/kernel/syntax/expression/type/Pi.h"

namespace Machinish {

void Pi::dump() {
  std::cout << "[Pi] (";
  binder.print();
  std::cout << " : ";
  domain.print();
  std::cout << ") → ";
  codomain.print();
  std::cout << std::endl;
}

std::string Pi::to_string() const {
  return "Π(" + binder.to_string() + " : " + domain.to_string() + ") → " +
         codomain.to_string();
}

void Pi::print(std::ostream &os) const { os << to_string(); }

} // namespace Machinish
