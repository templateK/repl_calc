add_executable(parser_test_exe parser_test.c)
add_executable(stack_test_exe stack_test.c)
target_link_libraries (parser_test_exe LINK_PUBLIC libparse)
target_link_libraries (stack_test_exe LINK_PUBLIC libstack)

add_test(parser_test parser_test_exe)
add_test(stack_test stack_test_exe)

set_tests_properties(parser_test
                     PROPERTIES PASS_REGULAR_EXPRESSION "SUCCESS")

set_tests_properties(stack_test
                     PROPERTIES PASS_REGULAR_EXPRESSION "SUCCESS")

add_custom_target(check
                  COMMAND ${CMAKE_CTEST_COMMAND}
                  # --verbose
                  --output-on-failure
                  DEPENDS parser_test_exe stack_test_exe
                  COMMENT "Running check with deps parser_test_exe"
                  )
