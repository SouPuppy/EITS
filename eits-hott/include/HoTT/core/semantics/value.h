// include/EITS/kernel/semantics/value.h

#pragma once

#include <variant>
#include <memory>

#include "HoTT/core/semantics/value/closure.h"
#include "HoTT/core/semantics/value/const.h"
#include "HoTT/core/semantics/value/neutral.h"

namespace EITS {

using ValueVariant = std::variant<
	std::shared_ptr<Closure>,
	std::shared_ptr<Constant>,
	std::shared_ptr<Neutral>
>;

struct Value : ValueVariant {
	~Value() = default;
	Value() {}
};

} // namespace Machinsih
