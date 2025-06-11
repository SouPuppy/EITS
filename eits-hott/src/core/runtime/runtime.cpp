// src/runtime/runtime.cpp

#include "HoTT/core/runtime/runtime.h"

#include <iostream>
#include <fstream>
#include <chrono>
#include <filesystem>
#include <map>

#include "HoTT/meta/version.h"
#include "HoTT/core/semantics/context.h"
#include "internal/instructions/snapshot.h"

#include <logger.h>
using namespace logger::log;

void save_meta(std::ostream& out) {
	auto now = std::chrono::system_clock::now();
	auto in_time_t = std::chrono::system_clock::to_time_t(now);
	out << "[meta]\n";
	out << "  - time: " << std::ctime(&in_time_t);
	out << "  - version: " << EITS::Meta::version() << "\n";
	out << std::endl;
}

namespace EITS {

void Runtime::init() {
	INFO("Initiating Runtime...")
	     << "HoTT kernel version: " + EITS::Meta::version();
	return ;
}

void Runtime::add_bind(std::string name, std::shared_ptr<Type> type) {
	ctx.add(name, type);
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
	std::string default_dir = std::filesystem::current_path();
	std::string default_name = "snapshot";

	std::cout << "Save directory (" << default_dir << "): ";
	std::string input_dir;
	std::getline(std::cin, input_dir);
	std::filesystem::path save_dir = input_dir.empty() ? default_dir : input_dir;

	std::cout << "Snapshot name (" << default_name << "): ";
	std::string input_name;
	std::getline(std::cin, input_name);
	std::string label = input_name.empty() ? default_name : input_name;

	if (!std::filesystem::exists(save_dir)) {
		try {
			std::filesystem::create_directories(save_dir);
		} catch (const std::exception& e) {
			std::cerr << "[Error] Failed to create directory: " << e.what() << std::endl;
			return;
		}
	}

	auto file_path = save_dir / (label + ".omac");

	std::ofstream out(file_path, std::ios::out | std::ios::trunc);
	if (!out) {
		std::cerr << "[Error] Cannot open file: " << file_path << std::endl;
		return;
	}

	DEBUG("Saving") << file_path;

	ContextSnapshot snap = create_snapshot(ctx, label);
	save_meta(out);
	save_context(snap, out);

	std::cout << "[OK] Snapshot saved: " << file_path << std::endl;
}


void Runtime::handle_exit() {
	exit(0);
}

} // namespace EITS
