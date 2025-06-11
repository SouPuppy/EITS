// src/internal/instructions/snapshot.cpp

#include "internal/instructions/snapshot.h"

#include <iostream>

#include "HoTT/core/semantics/context.h"

namespace EITS {

ContextSnapshot create_snapshot(const Context ctx, std::string label) {
	return ContextSnapshot{ctx, label};
}

void save_context(ContextSnapshot &snap, std::ostream &out) {
	out << "[context]\n";

	for (const auto& [key, value] : snap.ctx.gamma) {
		out << "def " << key << " : " << value->to_string() << "\n";
	}
	out << std::endl;
}

} // namespace EITS
