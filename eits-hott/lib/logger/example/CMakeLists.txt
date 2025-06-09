add_executable(logger_demo main.cpp)

target_link_libraries(logger_demo PRIVATE logger)
option(ENABLE_LOG_VERBOSE "Enable verbose logging" ON)
