# src/internal/instructions/CMakeLists.txt

add_library(internal_instructions STATIC
	snapshot.cpp
)

target_link_libraries(internal_instructions
	PRIVATE
		eits_hott_kernel_semantics
		eits_hott_headers
)

target_include_directories(internal_instructions
  PRIVATE
		../..
)
