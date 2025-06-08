# src/kernel/syntax/CMakeLists.txt

add_subdirectory(expression)

file(GLOB SOURCE_CODE
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(machinish_kernel_syntax STATIC
	${SOURCE_CODE}
)

target_include_directories(machinish_kernel_syntax
  PRIVATE
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(machinish_kernel_syntax
	PRIVATE
		logger
  PUBLIC
		internal_uid
		machinish_expression
)
