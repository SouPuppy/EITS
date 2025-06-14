// src/internal/uid/uid.h

#pragma once

#include <cstdint>
#include <string>

namespace EITS::Internal {

struct UIDGenerator {
	uint64_t last_timestamp = 0;
	uint64_t sequence = 0;
	uint16_t machine_id = 0;

	UIDGenerator() = default;
	explicit UIDGenerator(uint16_t machine_id);

	uint64_t next();
	std::string next_hex();
};

extern UIDGenerator globalUIDGenerator;

} // namespace EITS::Internal
