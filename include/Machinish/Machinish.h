// include/Machinish/Machinish.h

#pragma once

// Project version and build metadata
#include <Machinish/meta/version.h>

// Runtime system entry point (REPL, dispatch, reset)
#include <Machinish/kernel/runtime/runtime.h>

// Core syntax tree: expressions, types, universes, variables
#include <Machinish/kernel/syntax/expression/expression.h>
#include <Machinish/kernel/syntax/expression/term.h>
#include <Machinish/kernel/syntax/expression/type.h>
#include <Machinish/kernel/syntax/expression/universe.h>
#include <Machinish/kernel/syntax/expression/variable.h>
#include <Machinish/kernel/syntax/binder.h>

// Semantic layer: values, closures, evaluation environment
#include <Machinish/kernel/semantics/value.h>
#include <Machinish/kernel/semantics/env.h>
#include <Machinish/kernel/semantics/forms/Form.h>

// Basis tools: location tracking
#include <Machinish/kernel/basis/location.h>

// Error system: type errors, evaluation errors, source reporting
#include <Machinish/kernel/error/error.h>

namespace Machinish {



} // namespace Machinish
