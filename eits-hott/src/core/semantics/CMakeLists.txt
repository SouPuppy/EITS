# src/kernel/syntax/CMakeLists.txt

add_library(eits_hott_kernel_semantics STATIC
        value.cpp
)

add_subdirectory(term)
add_subdirectory(eliminator)

target_link_libraries(eits_hott_kernel_semantics
	PUBLIC
		eits_hott_kernel_semantics_constructor
		eits_hott_kernel_semantics_eliminator
)
