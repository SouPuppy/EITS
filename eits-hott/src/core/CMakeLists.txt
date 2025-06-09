# src/kernel/CMakeLists.txt

add_subdirectory(runtime)
add_subdirectory(basis)
add_subdirectory(syntax)
add_subdirectory(semantics)

add_library(eits_hott_kernel INTERFACE)

target_link_libraries(eits_hott_kernel
	INTERFACE
		eits_hott_kernel_basis
		eits_hott_kernel_runtime
		eits_hott_kernel_syntax
		eits_hott_kernel_semantics
)
