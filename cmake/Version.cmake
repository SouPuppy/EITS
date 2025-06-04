# cmake/Version.cmake

execute_process(
  COMMAND git describe --tags --always --dirty
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE GIT_DESCRIBE_VERSION
  OUTPUT_STRIP_TRAILING_WHITESPACE
  ERROR_QUIET
)

if(GIT_DESCRIBE_VERSION AND NOT GIT_DESCRIBE_VERSION STREQUAL "")
  set(DISPLAY_VERSION "${GIT_DESCRIBE_VERSION}")
  file(WRITE "${CMAKE_BINARY_DIR}/version.txt" "${DISPLAY_VERSION}\n")
else()
  if(EXISTS "${CMAKE_BINARY_DIR}/version.txt")
    file(READ "${CMAKE_BINARY_DIR}/version.txt" DISPLAY_VERSION)
    string(STRIP "${DISPLAY_VERSION}" DISPLAY_VERSION)
  else()
    set(DISPLAY_VERSION "${PROJECT_VERSION_BASE}")
  endif()
endif()

set(PROJECT_VERSION "${DISPLAY_VERSION}" CACHE INTERNAL "Project version")

set(VERSION_TEMPLATE "${CMAKE_SOURCE_DIR}/cmake/template/version.h.in")
set(VERSION_HEADER "${CMAKE_BINARY_DIR}/generated/include/Machinish/config/version.h")

configure_file(
  ${VERSION_TEMPLATE}
  ${VERSION_HEADER}
  @ONLY
  NEWLINE_STYLE UNIX
)

message(STATUS "[Machinish] Version: ${DISPLAY_VERSION}")
