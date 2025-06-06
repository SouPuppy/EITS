add_executable(demo main.cpp)

target_link_libraries(demo PRIVATE logger)
option(ENABLE_LOG_VERBOSE "Enable verbose logging" ON)
