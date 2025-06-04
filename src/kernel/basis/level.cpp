// src/kernel/basis/level.cpp

#include "Machinish/kernel/basis/level.h"

namespace Machinish::Kernel::Universe {

Level zero() {
	return Zero{};
}

Level succ(const Level& l) {
	return Succ{ std::make_shared<Level>(l) };
}

Level max(const Level& a, const Level& b) {
	return Max{ std::make_shared<Level>(a), std::make_shared<Level>(b) };
}

} // namespace Machinish::Kernel::Universe
