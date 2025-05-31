# src/info/CMakeLists.txt

add_library(machinish_info STATIC
	version.cpp
)

target_include_directories(machinish_info
	PUBLIC
		${PROJECT_SOURCE_DIR}/include
		${CMAKE_BINARY_DIR}/include
)
