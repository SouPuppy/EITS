// src/kernel/syntax/expression.cpp

#include "HoTT/core/syntax/expression/expression.h"

namespace EITS {

void Expression::dump() {
  std::visit([](auto &&arg) { arg->dump(); }, *this);
}

std::string Expression::to_string() const {
  return std::visit([](auto &&arg) { return arg->to_string(); }, *this);
}

void Expression::print(std::ostream &os) const {
  std::visit([&os](auto &&arg) { arg->print(os); }, *this);
}

} // namespace EITS
