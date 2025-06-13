// include/EITS/kernel/runtime/runtime.h

#pragma once

#include "HoTT/core/semantics/context.h"
#include "HoTT/core/syntax/expression/type.h"

namespace EITS {

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

	void add_bind(std::string name, std::shared_ptr<Expression> expr);
	
	void execute(Instruction instr);
	void handle_reset();
	void handle_dump();
	void handle_load();
	void handle_save();
	void handle_exit();
};

} // namespace EITS
