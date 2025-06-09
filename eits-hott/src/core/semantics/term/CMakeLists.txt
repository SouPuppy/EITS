# src/kernel/runtime/CMakeLists.txt

file(GLOB SOURCE_CODE
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(eits_hott_kernel_semantics_constructor STATIC
	${SOURCE_CODE}
)

target_link_libraries(eits_hott_kernel_semantics_constructor
	PRIVATE
		logger
  PUBLIC
		eits_hott_headers
)
