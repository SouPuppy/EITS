// include/Machinish/kernel/Types/universe.h

#pragma once

#include <string>

#include <Machinish/common.h>
#include <Machinish/kernel/term.h>

namespace Machinish {

struct Type_Universe : Type_Base {
	int level;

	Type_Universe(int _level): level(_level) {};
	std::string to_string() const override {
#ifdef MACHINISH_ENABLE_DEBUG
		return "(Universe) 𝒰 " + std::to_string(level);
#else
		return std::to_string(level);
#endif
	}
};

using Universe = std::shared_ptr<Type_Universe>;
inline Type makeUniverse(int level) {
	return std::make_shared<Type_Universe>(level);
}

} // namespace Machinish
