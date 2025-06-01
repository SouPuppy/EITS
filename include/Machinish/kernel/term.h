// include/Machinish/term.h

#pragma once

#include <memory>
#include <string>

namespace Machinish {

struct Type_Base {
	virtual ~Type_Base() = default;
	virtual std::string to_string() const = 0;
};
	
using Type = std::shared_ptr<Type_Base>;
bool operator==(const Type &lhs, const Type &rhs);

} // namespace Machinish
