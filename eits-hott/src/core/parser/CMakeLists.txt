# src/kernel/parser/CMakeLists.txt

add_subdirectory(lexer)

file(GLOB SOURCE_CODE
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(eits_hott_kernel_parser STATIC
	${SOURCE_CODE}
)

target_link_libraries(eits_hott_kernel_parser
	PRIVATE
		logger
		internal_charutil
  PUBLIC
		eits_hott_kernel_lexer
		internal_instructions
		eits_hott_headers
)
