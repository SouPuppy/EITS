// src/kernel/syntax/expression.cpp

#include "Machinish/kernel/syntax/expression/expression.h"

namespace Machinish {

void Expression::dump() {
  std::visit([](auto &&arg) { arg.dump(); }, *this);
}

std::string Expression::to_string() const {
  return std::visit([](auto &&arg) { return arg.to_string(); }, *this);
}

void Expression::print(std::ostream &os) const {
  std::visit([&os](auto &&arg) { arg.print(os); }, *this);
}

} // namespace Machinish
