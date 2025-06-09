// include/EITS/EITS.h

#pragma once

// Project version and build metadata
#include <HoTT/meta/version.h>

// Runtime system entry point (REPL, dispatch, reset)
#include <HoTT/core/runtime/runtime.h>

// Core syntax tree: expressions, types, universes, variables
#include <HoTT/core/basis/level.h>
#include <HoTT/core/syntax/binder.h>
#include <HoTT/core/syntax/expression/expression.h>

#include <HoTT/core/syntax/expression/term/variable.h>
#include <HoTT/core/syntax/expression/term/constant.h>

#include <HoTT/core/syntax/expression/type.h>
#include <HoTT/core/syntax/expression/type/Pi.h>
#include <HoTT/core/syntax/expression/type/Sigma.h>
#include <HoTT/core/syntax/expression/type/Id.h>

// Semantic layer: values, closures, evaluation environment
#include <HoTT/core/semantics/env.h>
#include <HoTT/core/semantics/value.h>

// Basis tools: location tracking
#include <HoTT/core/basis/location.h>

// Error system: type errors, evaluation errors, source reporting
#include <HoTT/core/error/error.h>
