# src/kernel/syntax/CMakeLists.txt

add_subdirectory(expression)

file(GLOB SOURCE_CODE
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(eits_hott_kernel_syntax STATIC
	${SOURCE_CODE}
)

target_include_directories(eits_hott_kernel_syntax
  PRIVATE
        ../..
)

target_link_libraries(eits_hott_kernel_syntax
	PRIVATE
		logger
  PUBLIC
		internal_uid
		eits_hott_expression
)
