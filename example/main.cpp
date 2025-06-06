#include <logger.h>

// Use shorthand logging functions
using namespace logger::log;

int main() {
	// Initialize logger with a custom file path (log/example.log)
	logger::init("log/example.log");

	// Developer log: internal debug or verbose information
	LOG("This is a DEV log message (usually low-level developer output).");

	// Informational message: general runtime status
	INFO("Application started successfully.");

	// Warning message: something might be wrong, but not critical
	WARNING("Configuration file not found. Using defaults.");

	// Error message: critical problem occurred
	ERROR("Failed to connect to the database.");

	// Debug message: technical details for developers
	DEBUG("User input received: 'example input'");

	// Default format (same as INFO unless overridden)
	logger::logger_default.log("This is a default log using the fallback format.", logger::DEFAULT);

	// OK message: operation completed successfully
	OK("Data processed successfully.");

	// Failed message: operation did not complete successfully
	FAILED("Data processing failed due to an unexpected error.");

	return 0;
}
