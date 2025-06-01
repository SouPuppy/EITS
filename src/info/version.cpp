// src/info/version.cpp

#include <string>

#include <Machinish/config/version.h>
#include <Machinish/info/version.h>

namespace Machinish::Info {
  std::string version() {
		return MACHINISH_VERSION_STRING;
	}
} // Machinish::Info
