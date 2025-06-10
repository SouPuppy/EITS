# eits-repl/CMakeLists.txt

# Automatically collect all source files in src/
file(GLOB_RECURSE EITS_REPL_SOURCES CONFIGURE_DEPENDS
	*.cpp
	*.c
)

add_executable(eits_repl ${EITS_REPL_SOURCES})

target_include_directories(eits_repl
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(eits_repl
	PRIVATE
		eits_hott
		logger
)
