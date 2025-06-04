# src/kernel/syntax/CMakeLists.txt

add_subdirectory(expression)

add_library(machinish_kernel_syntax STATIC
  binder.cpp
)

target_link_libraries(machinish_kernel_syntax
  PUBLIC
    machinish_expression
)
