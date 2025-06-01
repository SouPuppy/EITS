# src/kernel/CMakeLists.txt

add_library(machinish_kernel STATIC
	type.cpp
)

target_include_directories(machinish_kernel
	PUBLIC
		${PROJECT_SOURCE_DIR}/include
		${CMAKE_BINARY_DIR}/include
)
