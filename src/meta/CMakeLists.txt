# src/meta/CMakeLists.txt

add_library(machinish_meta STATIC
	version.cpp
)

target_link_libraries(machinish_meta PUBLIC machinish_headers)
