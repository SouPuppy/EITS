// include/Machinish/kernel/semantics/value.h

#pragma once

#include <variant>
#include <memory>

#include "Machinish/kernel/syntax/expression/term.h"
#include "Machinish/kernel/semantics/value/closure.h"
#include "Machinish/kernel/semantics/value/const.h"
#include "Machinish/kernel/semantics/value/neutral.h"

namespace Machinish {

using ValueVariant = std::variant<
	std::shared_ptr<Closure>,
	std::shared_ptr<Const>,
	std::shared_ptr<Neutral>
>;

struct Value : ValueVariant, Term {
	
};

} // namespace Machinsih
