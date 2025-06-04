// src/runtime/runtime.cpp

#include "Machinish/kernel/runtime/runtime.h"

#include <iostream>

#include "Machinish/meta/version.h"
#include "internal/instructions/exit.h"

namespace Machinish {

Runtime::~Runtime() {}

void Runtime::init() {
	std::cout << "[Initiating Runtime]\n" << std::endl;
	std::cout << "  Machinish kernel version: " << Machinish::Meta::version() << std::endl;
	return ;
}

void Runtime::execute(Instruction instruction) {
	switch (instruction) {
		case Instruction::Exit:
			
			break;
		default:
			break;
	}
}

} // namespace Machinish
