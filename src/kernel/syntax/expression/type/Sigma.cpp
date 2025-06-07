// src/kernel/syntax/expression/type/Sigma.h

#include <iostream>

#include "Machinish/kernel/syntax/expression/type/Sigma.h"

namespace Machinish {

void Sigma::dump() {
  std::cout << "[Sigma] (";
  binder.print();
  std::cout << " : ";
  domain.print();
  std::cout << ") → ";
  codomain.print();
  std::cout << std::endl;
}

std::string Sigma::to_string() const {
  return "Σ(" + binder.to_string() + " : " + domain.to_string() + ") → " +
         codomain.to_string();
}

void Sigma::print(std::ostream &os) const { os << to_string(); }

} // namespace Machinish
