add_executable(test_level
	test_level.cpp
)

target_link_libraries(test_level
	PRIVATE
		gtest_main
		eits_hott
)

target_link_libraries(test_level PRIVATE
	eits_hott_headers
)

#FIXME - ?
# gtest_discover_tests(test_level)
add_test(NAME LevelTests COMMAND test_level)