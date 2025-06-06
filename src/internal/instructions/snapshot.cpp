// src/internal/instructions/snapshot.cpp

#include "internal/instructions/snapshot.h"

#include <iostream>

#include "Machinish/kernel/semantics/context.h"

namespace Machinish {

ContextSnapshot create_snapshot(const Context ctx, std::string label) {
	return ContextSnapshot{ctx, label};
}

void save(ContextSnapshot& ctx, const std::filesystem::path& path) {
	std::filesystem::path file = path / (ctx.label + ".omac");

	if (path.empty()) {
		std::cout << "Saving context to default path." << std::endl;
	} else {
		std::cout << "Saving context to: " << file << std::endl;
	}
}

} // namespace Machinish
