# test/kernel/CMakeLists.txt

add_executable(test_kernel types.cpp)

target_link_libraries(test_kernel
	PRIVATE
  GTest::gtest_main
  GTest::gtest
	machinish
)

gtest_discover_tests(test_kernel)
