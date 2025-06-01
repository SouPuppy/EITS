# test/CMakeLists.txt

enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
option(CODE_COVERAGE "Enable coverage reporting" ON)

if(CODE_COVERAGE)
  add_compile_options(--coverage)
  add_link_options(--coverage)
endif()

FetchContent_MakeAvailable(googletest)

add_executable(
  hello_test
  hello_test.cpp
)
target_link_libraries(
  hello_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)
