// src/runtime/runtime.cpp

#include "Machinish/kernel/runtime/runtime.h"
#include "Machinish/kernel/runtime/context.h"

#include <iostream>

#include "Machinish/meta/version.h"

namespace Machinish {

void Runtime::init() {
	std::cout << "[Initiating Runtime]" << std::endl;
	std::cout << " - Machinish kernel version: " << Machinish::Meta::version() << std::endl;
	return ;
}

void Runtime::execute(Instruction instruction) {
//NOTE - refactor switch with handler
	switch (instruction) {
		case Instruction::Reset: ctx.clear(); break;
		case Instruction::Save:	ctx.save(std::filesystem::current_path()); break;
		case Instruction::Load:	ctx.load(std::filesystem::current_path()); break;
		case Instruction::Dump:	ctx.show(); break;
		case Instruction::Exit:	exit(0); break;
		default: break;
	}
}

} // namespace Machinish
