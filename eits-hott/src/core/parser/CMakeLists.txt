# src/kernel/parser/CMakeLists.txt

file(GLOB SOURCE_CODE
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(eits_hott_kernel_parser STATIC
	${SOURCE_CODE}
)

target_link_libraries(eits_hott_kernel_parser
	PRIVATE
		logger
  PUBLIC
		internal_instructions
		eits_hott_headers
)
