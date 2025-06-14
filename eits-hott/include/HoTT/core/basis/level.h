// include/EITS/basis/levelType.h

#pragma once

#include <memory>
#include <string>
#include <variant>

namespace EITS {

struct Level;
using LevelPtr = std::shared_ptr<Level>;

struct Zero {};
struct Succ {
	LevelPtr pred;
};
struct Max {
	LevelPtr l1, l2;
};

using LevelType = std::variant<Zero, Succ, Max>;

// REVIEW - should update to value-based Level?
struct Level {
	std::shared_ptr<LevelType> level;

	explicit Level() : level(std::make_shared<LevelType>(Zero{})) {}
	explicit Level(int t);
	explicit Level(LevelType t);

	static Level zero();
	static Level succ(const Level &l);
	static Level max(const Level &l1, const Level &l2);

	std::string to_string() const;
};

} // namespace EITS
