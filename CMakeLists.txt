# CMakeLists files in this project can
# refer to the root source directory of the project as ${CALCUlATOR_SOURCE_DIR} and
# to the root binary directory of the project as ${CALCUlATOR_BINARY_DIR}.
cmake_minimum_required (VERSION 3.18.0)
project (CALCULATOR)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Recurse into the "app" and "libparse" subdirectories. This does not actually
# cause another cmake executable to run. The same process will walk through
# the project's entire directory structure.
add_subdirectory (app)
add_subdirectory (libstack)
add_subdirectory (libstack2)
add_subdirectory (libstack3)
add_subdirectory (libstack4)
add_subdirectory (libarray)

get_target_property(libstack3_include libstack3 INCLUDE_DIRECTORIES)
get_target_property(libstack4_include libstack4 INCLUDE_DIRECTORIES)
get_target_property(libarray_include libarray INCLUDE_DIRECTORIES)

add_subdirectory (libparse)

enable_testing()
add_subdirectory (test)
