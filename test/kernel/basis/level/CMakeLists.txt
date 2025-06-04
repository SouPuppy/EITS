add_executable(test_level
	test_level.cpp
)

target_link_libraries(test_level
	PRIVATE
		gtest_main
		machinish
)

target_link_libraries(test_level PRIVATE
	machinish_headers
)

gtest_discover_tests(test_level)
