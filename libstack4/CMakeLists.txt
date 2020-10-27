# Create a library called "libparse" which includes the source file "libparse.c".
# The extension is already found. Any number of sources could be listed here.
add_library (libstack4 libstack4.h libstack4.c)

# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to "libparse"
target_include_directories (libstack4 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
