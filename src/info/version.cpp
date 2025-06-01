// src/info/version.cpp

#include <Machinish/config/version.h>
#include <Machinish/info/version.h>

#include <string>

namespace Machinish::Info {
  std::string version() {
		return MACHINISH_VERSION_STRING;
	}
} // Machinish::Info
