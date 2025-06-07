// src/kernel/basis/level.cpp

#include "Machinish/kernel/basis/level.h"

#include <memory>
#include <string>

template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

namespace Machinish {

	Level::Level(int t) {
		Level res = Level::zero();
		while (t--) {
			res = Level::succ(res);
		}
		level = res.level;
	}

Level::Level(LevelType t)
  : level(std::make_shared<LevelType>(std::move(t))) {}

Level Level::zero() {
	return Level(LevelType(Zero{}));
}

Level Level::succ(const Level& l) {
	return Level(LevelType(Succ{
		.pred = std::make_shared<Level>(l)
	}));
}

Level Level::max(const Level& l1, const Level& l2) {
	return Level(LevelType(Max{
		.l1 = std::make_shared<Level>(l1),
		.l2 = std::make_shared<Level>(l2)
	}));
}

std::string Level::to_string() const {
	return std::visit(overloaded {
		[](const Zero&) -> std::string {
			return "0";
		},
		[](const Succ& s) -> std::string {
			return "S(" + s.pred->to_string() + ")";
		},
		[](const Max& m) -> std::string {
			return "max(" + m.l1->to_string() + ", " + m.l2->to_string() + ")";
		}
	}, *level);
}

} // namespace Machinish
