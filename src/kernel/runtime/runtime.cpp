// src/runtime/runtime.cpp

#include "Machinish/kernel/runtime/runtime.h"
#include "Machinish/kernel/semantics/context.h"
#include "internal/instructions/snapshot.h"

#include <iostream>
#include <functional>
#include <map>

#include "Machinish/meta/version.h"

namespace Machinish {

void Runtime::init() {
	std::cout << "[Initiating Runtime]" << std::endl;
	std::cout << "  - Machinish kernel version: " << Machinish::Meta::version() << std::endl;
	return ;
}

void Runtime::execute(Instruction instruction) {
	using Handler = void (Runtime::*)();
	
	static const std::map<Instruction, Handler> dispatch_table = {
		{Instruction::Reset, &Runtime::handle_reset},
		{Instruction::Dump,  &Runtime::handle_dump},
		{Instruction::Load,  &Runtime::handle_load},
		{Instruction::Save,  &Runtime::handle_save},
		{Instruction::Exit,  &Runtime::handle_exit},
	};

	// Dispatch the instruction to the appropriate handler method
	auto it = dispatch_table.find(instruction);
	if (it != dispatch_table.end()) {
		(this->*it->second)();
	} else {
		std::cerr << "[Runtime] Unknown instruction.\n";
	}
}

void Runtime::handle_reset() {
	ctx.clear();
}

void Runtime::handle_dump() {
	ctx.dump();
}

void Runtime::handle_load() {
	// ctx = load_from_path(...);
}

void Runtime::handle_save() {
	ContextSnapshot snap = create_snapshot(ctx, "snapshot");
	save_context(snap, std::filesystem::current_path());
}

void Runtime::handle_exit() {
	exit(0);
}

} // namespace Machinish
