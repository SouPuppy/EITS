// src/kerne/syntax/variable.cpp

#include "Machinish/kernel/syntax/variable.h"

namespace Machinish {

// Variable::Variable(ExpressionPtr _name, ExpressionPtr _type)
// 	: name(_name), type(_type) {};

void Variable::dump() {
  std::cout << "[Var]" << std::endl;
  std::cout << " - " << "name: '" << name << "'" << std::endl;
  std::cout << " - " << "type: " << type.to_string() << std::endl;
}

std::string Variable::to_string() const {
	if (name == "")
		return "_" + type.to_string();
	else
		return name + " : " + type.to_string();
}

void Variable::print(std::ostream &os) const { os << to_string(); }

} // namespace Machinish
