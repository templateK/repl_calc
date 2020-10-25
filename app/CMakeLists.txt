# Add executable called "calc" that is built from the source files
# "main.c". The extensions are automatically found.
add_executable (calc main.c)

# Link the executable to the libparse library. Since the "libparse" library has
# public include directories we will use those link directories when building
# "calc" binary.
target_link_libraries (calc LINK_PUBLIC libparse libarray)

add_custom_target(run
                  COMMAND calc
                  WORKING_DIRECTORY $<TARGET_FILE_DIR:calc>)
                   
