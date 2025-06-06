# src/kernel/CMakeLists.txt

file(GLOB SOURCE_CODE
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(machinish_forms STATIC
  ${SOURCE_CODE}
)

target_include_directories(machinish_forms
	PUBLIC
		${PROJECT_SOURCE_DIR}/include
		${CMAKE_BINARY_DIR}/include
)

