// include/Machinish/kernel/runtime/runtime.h

#pragma once

#include "Machinish/kernel/semantics/context.h"
#include "Machinish/kernel/syntax/expression/type.h"

namespace Machinish {

enum class Instruction {
	Reset,
	Dump,
	Load,
	Save,
	Exit,
	Def,
};

struct Runtime {
	Context ctx = Context{ .parent = nullptr };

	~Runtime() = default;
	void init();

	void add_bind(std::string name, std::shared_ptr<Type> type);
	
	void execute(Instruction instr);
	void handle_reset();
	void handle_dump();
	void handle_load();
	void handle_save();
	void handle_exit();
};

} // namespace Machinish
