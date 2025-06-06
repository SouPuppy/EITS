// include/Machinish/kernel/runtime/runtime.h

#include "../../../src/internal/instructions/snapshot.h"

#pragma once

namespace Machinish {

enum class Instruction {
	Reset,
	Dump,
	Load,
	Save,
	Exit,
};

struct Runtime {
	Context ctx;
	
	~Runtime() = default;
	void init();
	void execute(Instruction instr);

	void handle_reset();
	void handle_dump();
	void handle_load();
	void handle_save();
	void handle_exit();
};

} // namespace Machinish
