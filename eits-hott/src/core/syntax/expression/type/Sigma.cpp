// src/kernel/syntax/expression/type/Sigma.h

#include <iostream>

#include "HoTT/core/syntax/expression/type/Sigma.h"

namespace EITS {

void Sigma::dump() {
  std::cout << "[Sigma] (";
  binder.print();
  std::cout << ") → ";
  codomain.print();
  std::cout << std::endl;
}

std::string Sigma::to_string() const {
  return "Σ(" + binder.to_string() + ") → " + codomain.to_string();
}

void Sigma::print(std::ostream &os) const { os << to_string(); }

} // namespace EITS
