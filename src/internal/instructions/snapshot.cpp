// src/internal/instructions/snapshot.cpp

#include "internal/instructions/snapshot.h"

#include <iostream>
#include <fstream>
#include <filesystem>

#include "Machinish/kernel/semantics/context.h"

namespace Machinish {

ContextSnapshot create_snapshot(const Context ctx, std::string label) {
	return ContextSnapshot{ctx, label};
}

void save_context(ContextSnapshot& ctx, const std::filesystem::path& path) {
	std::string label = ctx.label.empty() ? "noname" : ctx.label;
	std::filesystem::path file = path / (label + ".omac");

	if (path.empty()) {
		std::cout << "Saving context to default path." << std::endl;
	} else {
		std::cout << "Saving context to: " << file << std::endl;
	}

	if (!std::filesystem::exists(path)) {
		std::cout << "[Warning] Path does not exist, creating: " << path << std::endl;
		std::filesystem::create_directories(path);
	}

	std::ofstream out(file, std::ios::app);
	if (!out) {
		std::cerr << "[Error] Cannot open file: " << file << std::endl;
		return;
	}

	out << "[Machinish Context Snapshot]\n";
}

} // namespace Machinish
