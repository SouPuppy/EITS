# src/kernel/syntax/CMakeLists.txt

add_subdirectory(expression)

add_library(machinish_kernel_syntax INTERFACE)

target_link_libraries(machinish_kernel_syntax
  INTERFACE
    machinish_expression
)
