// src/meta/version.cpp

#include <string>

// generated
#include "Machinish/config/version.h"

#include "Machinish/meta/version.h"

namespace Machinish::Meta {
  std::string version() {
		return MACHINISH_VERSION_STRING;
	}
} // Machinish::Meta
