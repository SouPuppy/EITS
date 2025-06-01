// include/Machinish/kernel/Types/universe.h

#pragma once

#include <string>

#include <Machinish/kernel/type.h>

namespace Machinish {

struct Universe : Type {
	std::string to_string() const override {
		return "Universe";
	}
};

} // namespace Machinish
