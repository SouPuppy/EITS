// include/Machinish/Machinish.h

#pragma once

// Project version and build metadata
#include <Machinish/meta/version.h>

// Runtime system entry point (REPL, dispatch, reset)
#include <Machinish/kernel/runtime/runtime.h>

// Core syntax tree: expressions, types, universes, variables
#include <Machinish/kernel/basis/level.h>
#include <Machinish/kernel/syntax/binder.h>
#include <Machinish/kernel/syntax/expression/expression.h>

#include <Machinish/kernel/syntax/expression/term/variable.h>

#include <Machinish/kernel/syntax/expression/type.h>
#include <Machinish/kernel/syntax/expression/type/Pi.h>
#include <Machinish/kernel/syntax/expression/type/Sigma.h>
#include <Machinish/kernel/syntax/expression/type/Id.h>

// Semantic layer: values, closures, evaluation environment
#include <Machinish/kernel/semantics/env.h>
#include <Machinish/kernel/semantics/value.h>

// Basis tools: location tracking
#include <Machinish/kernel/basis/location.h>

// Error system: type errors, evaluation errors, source reporting
#include <Machinish/kernel/error/error.h>
