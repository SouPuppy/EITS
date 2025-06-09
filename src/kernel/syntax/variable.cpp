// src/kerne/syntax/variable.cpp

#include "../../../include/Machinish/kernel/syntax/expression/term/variable.h"
#include "internal/uid/uid.h"
#include <logger.h>

using namespace logger::log;

namespace Machinish {

BoundVariable::BoundVariable(Expression type) : type(type) {}

Variable::Variable() {
	// name = std::to_string(Internal::globalUIDGenerator.next());
	name = Internal::globalUIDGenerator.next_hex();
}

Variable::Variable(std::string name) : name(name), value(FreeVariable()) {}

Variable::Variable(std::string name, Expression type) : name(name), value(BoundVariable(type)) {}

void Variable::dump() {
	if (std::holds_alternative<FreeVariable>(value)) {
		DEBUG << "FreeVariable: " + name;
	} else if (std::holds_alternative<BoundVariable>(value)) {
		DEBUG << "BoundVariable: " + name + " : " + std::get<BoundVariable>(value).type.to_string();
	}
}

std::string Variable::to_string() const {
	if (std::holds_alternative<FreeVariable>(value)) {
		return "FreeVariable: " + name;
	} else if (std::holds_alternative<BoundVariable>(value)) {
		return "BoundVariable: " + name + " : " + std::get<BoundVariable>(value).type.to_string();
	}
	return "Unknown Variable";
}

void Variable::print(std::ostream& os) const {
	os << to_string();
}

bool Variable::is_free() {
	return std::holds_alternative<FreeVariable>(value);
}

} // namespace Machinish
