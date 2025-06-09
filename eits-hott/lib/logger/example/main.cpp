#include <logger.h>  // Make sure this path matches your include directory

using namespace logger::log;

int main() {
	// Initialize logging system; will create a log file under ./log/yyyy-mm-dd_HH-MM-SS.log
	logger::init();

	// Basic log with title, no payload
	LOG("Default log with title");

	// Simple debug log with single line content
	DEBUG << "This is a debug message.";

	// Multi-line log with a title
	LOG("System Init") 
		<< "Boot sequence started"
		<< "Loading kernel..."
		<< "Kernel loaded successfully.";

	// One-liner stream (log header only, no title)
	LOG << "line1" << "line2";

	// Error and OK messages
	ERROR("Startup failed") << "Missing configuration file: config.yaml";
	OK("Startup successful") << "All services online.";

	// Warning with no payload
	WARNING("Low memory detected");

	// INFO with details
	INFO("Launching service") << "Service: Database" << "Port: 5432";

	return 0;
}
