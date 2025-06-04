// include/Machinish/kernel/runtime/runtime.h

#include <Machinish/kernel/runtime/context.h>

#pragma once

namespace Machinish {

enum class Instruction {
	Load,
	Save,
	Exit
};

struct Runtime {
	Context ctx;
	
	~Runtime();
	void init();
	void execute(Instruction instr);
};

} // namespace Machinish
