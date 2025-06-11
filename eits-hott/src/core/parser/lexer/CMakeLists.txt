# src/kernel/lexer/CMakeLists.txt

add_subdirectory(dfa)
add_subdirectory(stratagy)

file(GLOB SOURCE_CODE
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(eits_hott_kernel_lexer STATIC
	${SOURCE_CODE}
)

target_link_libraries(eits_hott_kernel_lexer
	PRIVATE
		logger
		internal_charutil
  PUBLIC
		internal_instructions
		eits_hott_headers
		eits_hott_kernel_lexer_dfa
		eits_hott_kernel_lexer_stratagy
)
