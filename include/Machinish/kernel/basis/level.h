// include/Machinish/basis/level.h

#pragma once
#include <memory>
#include <variant>

namespace Machinish::Kernel::Universe {

struct Zero {};
struct Succ;
struct Max;

using Level = std::variant<Zero, Succ, Max>;

struct Succ {
	std::shared_ptr<Level> pred;
};

struct Max {
	std::shared_ptr<Level> l1, l2;
};

Level zero();
Level succ(const Level& l);
Level max(const Level& a, const Level& b);

} // namespace Machinish::Kernel::Universe
