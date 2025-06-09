# src/CMakeLists.txt

add_subdirectory(common)
add_subdirectory(meta)
add_subdirectory(internal)
add_subdirectory(core)

add_library(eits_hott INTERFACE)

target_link_libraries(eits_hott INTERFACE
	eits_hott_kernel
	eits_hott_meta
)
