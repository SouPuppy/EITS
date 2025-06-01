# test/CMakeLists.txt

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
option(CODE_COVERAGE "Enable coverage reporting" ON)

FetchContent_MakeAvailable(googletest)

include(GoogleTest)

add_subdirectory(kernel)
