// include/Machinish/type.h

#pragma once

#include <string>

namespace Machinish {

struct Type {
	virtual ~Type() = default;
	virtual std::string to_string() const = 0;
};

} // namespace Machinish
