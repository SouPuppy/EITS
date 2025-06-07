# src/kernel/CMakeLists.txt

file(GLOB SOURCE_CODE
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/type/*.cpp
)

add_library(machinish_expression STATIC
  ${SOURCE_CODE}
)

target_include_directories(machinish_expression
  PRIVATE
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(machinish_expression
	PRIVATE
		internal_charutil
		machinish_kernel_basis
)

target_link_libraries(machinish_expression
	PUBLIC
		machinish_headers
)
