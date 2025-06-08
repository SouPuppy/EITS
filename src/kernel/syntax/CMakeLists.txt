# src/kernel/syntax/CMakeLists.txt

add_subdirectory(expression)

add_library(machinish_kernel_syntax STATIC
  binder.cpp
	variable.cpp
)

target_link_libraries(machinish_kernel_syntax
	PRIVATE
		logger
  PUBLIC
    machinish_expression
)
