# Create a library called "libparse" which includes the source file "libparse.c".
# The extension is already found. Any number of sources could be listed here.
add_library (libparse libparse.h libparse.c)

# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to "libparse"
target_include_directories (libparse PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${libstack3_include}
  ${libarray_include})

target_link_libraries(libparse libstack3 libarray)
