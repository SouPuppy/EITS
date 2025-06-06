// src/internal/instructions/snapshot.cpp

#include "internal/instructions/snapshot.h"

#include <iostream>

#include "Machinish/kernel/semantics/context.h"

namespace Machinish {

ContextSnapshot create_snapshot(const Context ctx, std::string label) {
	return ContextSnapshot{ctx, label};
}

void save_context(ContextSnapshot& snap, std::ostream& out) {
	out << "[context]";
	int i = 0;
	for (const auto& [key, value] : snap.ctx.entries) {
		out << "\n" << ++i;
		out << "\n  - term : " << key;
		out << "\n  - type : " << value->to_string();
	}
	out << std::endl;
}

} // namespace Machinish
