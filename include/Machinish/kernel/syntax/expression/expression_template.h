// include/kernel/syntax/expression/expression_template.h

#pragma once

#include <string>
#include <memory>
#include <iostream>

namespace Machinish {

struct ExpressionTemplate {
  virtual void dump() = 0;
  virtual std::string to_string() const = 0;
  virtual void print(std::ostream& os = std::cout) const = 0;
};

using ExpressionPtr = std::shared_ptr<ExpressionTemplate>;

} // namespace Machinish
