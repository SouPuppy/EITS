// src/internal/uid/uid.h

#pragma once

#include <cstdint>

namespace Machinish::Internal {

struct UIDGenerator {
	uint64_t last_timestamp = 0;
	uint64_t sequence = 0;
	uint16_t machine_id = 0;

	UIDGenerator() = default;
	explicit UIDGenerator(uint16_t machine_id);

	uint64_t next();
};

} // namespace Machinish::Internal
