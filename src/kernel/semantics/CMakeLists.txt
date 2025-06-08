# src/kernel/syntax/CMakeLists.txt

add_library(machinish_kernel_semantics STATIC
  value.cpp
)

add_subdirectory(constructor)
add_subdirectory(eliminator)

target_link_libraries(machinish_kernel_semantics
	PUBLIC
		machinish_kernel_semantics_constructor
		machinish_kernel_semantics_eliminator
)
