# src/kernel/CMakeLists.txt

file(GLOB SOURCE_CODE
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(machinish_expression STATIC
  ${SOURCE_CODE}
)

target_link_libraries(machinish_expression
	PUBLIC
		machinish_headers
)