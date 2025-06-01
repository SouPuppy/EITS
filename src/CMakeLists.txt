# src/CMakeLists.txt

add_subdirectory(info)
add_subdirectory(kernel)

add_library(machinish INTERFACE)

target_link_libraries(machinish
	INTERFACE
		machinish_info
		machinish_kernel
)

target_include_directories(machinish
	INTERFACE
		${PROJECT_SOURCE_DIR}/include
)
