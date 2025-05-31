// src/info/version.cpp

#include <Machinish/config/version.hpp>
#include <Machinish/info/version.hpp>

#include <string>

namespace Machinish::Info {
  std::string version() {
		return MACHINISH_VERSION_STRING;
	}
} // Machinish::Info
