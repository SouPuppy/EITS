// include/HoTT/core/runtime/engine.h

#pragma once

#include "HoTT/core/runtime/runtime.h"

namespace EITS {

struct Engine {
	Runtime runtime;
	
	Engine();
	void init();

	// commands
	void define(std::string expr);
};

} // namespace EITS
