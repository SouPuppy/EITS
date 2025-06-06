// src/runtime/runtime.cpp

#include "Machinish/kernel/runtime/runtime.h"

#include <iostream>
#include <fstream>
#include <chrono>
#include <filesystem>
#include <map>

#include "Machinish/meta/version.h"
#include "Machinish/kernel/semantics/context.h"
#include "internal/instructions/snapshot.h"

void save_meta(std::ostream& out) {
	auto now = std::chrono::system_clock::now();
	auto in_time_t = std::chrono::system_clock::to_time_t(now);
	out << "[meta]\n";
	out << "  - time: " << std::ctime(&in_time_t);
	out << "  - version: " << Machinish::Meta::version() << "\n";
	out << std::endl;
}

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
	std::string label = "snapshot";
	auto current_dir = std::filesystem::current_path();
	auto file_path = current_dir / (label + ".omac");

	if (!std::filesystem::exists(current_dir)) {
		std::filesystem::create_directories(current_dir);
	}

	std::ofstream out(file_path, std::ios::out | std::ios::trunc);
	if (!out) {
		std::cerr << "[Error] Cannot open file: " << file_path << std::endl;
		return;
	}

	ContextSnapshot snap = create_snapshot(ctx, label);
	save_meta(out);
	save_context(snap, out);
}

void Runtime::handle_exit() {
	exit(0);
}

} // namespace Machinish
