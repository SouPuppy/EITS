# src/kernel/CMakeLists.txt

add_subdirectory(runtime)
add_subdirectory(basis)
add_subdirectory(syntax)
add_subdirectory(semantics)

add_library(machinish_kernel INTERFACE)

target_link_libraries(machinish_kernel
	INTERFACE
		machinish_kernel_basis
		machinish_kernel_runtime
		machinish_kernel_syntax
		machinish_kernel_semantics
)
