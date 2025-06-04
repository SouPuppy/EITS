# src/CMakeLists.txt

add_subdirectory(common)
add_subdirectory(meta)
add_subdirectory(internal)
add_subdirectory(kernel)

add_library(machinish INTERFACE)

target_link_libraries(machinish INTERFACE
	machinish_kernel
	machinish_meta
)
