# examples/CMakeLists.txt

add_executable(demo main.cpp)

target_link_libraries(demo 
	PRIVATE
	eits_hott
	logger
	internal_display
	)
