// src/internal/instructions/context.h

#pragma once

#include "Machinish/kernel/semantics/context.h"

namespace Machinish {

struct ContextSnapshot {
	Context ctx;
	std::string label;
};

ContextSnapshot create_snapshot(const Context ctx, std::string label);
void save_context(ContextSnapshot& snap, std::ostream& os);
// void load(ContextSnapshot& ctx, const std::filesystem::path& path);
// void inspect(ContextSnapshot& ctx);

} // namespace Machinish
