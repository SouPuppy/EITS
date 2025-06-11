// include/EITS/kernel/syntax/expression/term/const.h

#pragma once

#include "HoTT/core/syntax/expression/expression.h"
#include "HoTT/core/syntax/expression/term.h"
#include <memory>
#include <string>

namespace EITS {

struct Constant : Term{
	std::string name;
	std::shared_ptr<Type> type;
	~Constant() = default;
	Constant(std::string name, std::shared_ptr<Type> type) : name(name), type(type) {}
	std::string to_string() const override {
		return "`" + name + "` : " + type->to_string();
	}
	void dump() override {
		std::cout << "[Constant] " << to_string() << "\n";
	}
};

}; // namespace EITS
