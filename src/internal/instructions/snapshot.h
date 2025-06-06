// src/internal/instructions/context.h

#pragma once

#include "Machinish/kernel/semantics/context.h"

#include <filesystem>

namespace Machinish {

struct ContextSnapshot {
	Context ctx;
	std::string label;
};

ContextSnapshot create_snapshot(const Context ctx, std::string label = "default");
void save_context(ContextSnapshot& ctx, const std::filesystem::path& path);
// void load(ContextSnapshot& ctx, const std::filesystem::path& path);
// void inspect(ContextSnapshot& ctx);

} // namespace Machinish
