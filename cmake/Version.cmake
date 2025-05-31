# cmake/Version.cmake

execute_process(
  COMMAND git describe --tags --always --dirty
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE GIT_DESCRIBE_VERSION
  OUTPUT_STRIP_TRAILING_WHITESPACE
  ERROR_QUIET
)

if(GIT_DESCRIBE_VERSION)
  set(DISPLAY_VERSION ${GIT_DESCRIBE_VERSION})
  file(WRITE ${CMAKE_BINARY_DIR}/version.txt "${DISPLAY_VERSION}\n")
else()
  if(EXISTS ${CMAKE_BINARY_DIR}/version.txt)
    file(READ ${CMAKE_BINARY_DIR}/version.txt DISPLAY_VERSION)
    string(STRIP "${DISPLAY_VERSION}" DISPLAY_VERSION)
  else()
    set(DISPLAY_VERSION ${PROJECT_VERSION})
  endif()
endif()

configure_file(
  ${CMAKE_SOURCE_DIR}/cmake/template/version.hpp.in
  ${CMAKE_BINARY_DIR}/include/Machinish/config/version.hpp
  @ONLY
)

message(STATUS "[Machinish] Version: ${DISPLAY_VERSION}")
