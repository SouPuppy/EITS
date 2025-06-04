add_executable(test_internal_uid
	test_uid.cpp
)

target_link_libraries(test_internal_uid
	PRIVATE
		gtest_main
		internal_uid
)

target_include_directories(test_internal_uid PRIVATE
	${PROJECT_SOURCE_DIR}/src
)

add_test(NAME UIDGeneratorTests COMMAND test_internal_uid)
