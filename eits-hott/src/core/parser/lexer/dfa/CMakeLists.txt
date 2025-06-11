# src/kernel/lexer/dfa/CMakeLists.txt

file(GLOB SOURCE_CODE
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(eits_hott_kernel_lexer_dfa STATIC
	${SOURCE_CODE}
)

target_link_libraries(eits_hott_kernel_lexer_dfa
	PRIVATE
		internal_charutil
		logger
  PUBLIC
		eits_hott_headers
)
