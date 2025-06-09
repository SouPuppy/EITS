// src/internal/uid/uid.cpp

#include "internal/uid/uid.h"

#include <chrono>
#include <mutex>
#include <sstream>

namespace EITS::Internal {

static std::mutex uid_mutex;

static uint64_t current_millis() {
	using namespace std::chrono;
	return duration_cast<milliseconds>(
		system_clock::now().time_since_epoch()
	).count();
}

UIDGenerator::UIDGenerator(uint16_t machine_id)
	: last_timestamp(0), sequence(0), machine_id(machine_id & 0x3FF) {}

uint64_t UIDGenerator::next() {
	constexpr uint64_t machine_bits = 10;
	constexpr uint64_t sequence_bits = 12;
	constexpr uint64_t max_sequence = (1 << sequence_bits) - 1;

	std::lock_guard<std::mutex> lock(uid_mutex);

	uint64_t timestamp = current_millis();

	if (timestamp == last_timestamp) {
		sequence++;
		if (sequence > max_sequence) {
			// Wait for next millisecond
			while ((timestamp = current_millis()) <= last_timestamp);
			sequence = 0;
		}
	} else {
		sequence = 0;
		last_timestamp = timestamp;
	}

	return ((timestamp & 0x1FFFFFFFFFF) << (machine_bits + sequence_bits)) |
	       ((machine_id & 0x3FF) << sequence_bits) | (sequence & max_sequence);
}

std::string UIDGenerator::next_hex() {
    uint64_t uid = next();
    std::stringstream ss;
    ss << "0x" << std::hex << std::uppercase << uid;
    return ss.str();
}

UIDGenerator globalUIDGenerator;

} // namespace EITS::Internal
