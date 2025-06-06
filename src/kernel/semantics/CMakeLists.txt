# src/kernel/syntax/CMakeLists.txt

add_subdirectory(forms)

add_library(machinish_kernel_semantics STATIC
  value.cpp
)

target_link_libraries(machinish_kernel_semantics
  PUBLIC
    machinish_forms
)
