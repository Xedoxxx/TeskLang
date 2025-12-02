add_executable(test_tesk test_lexer.c)
target_link_libraries(test_tesk tesk)
target_include_directories(test_tesk PRIVATE  ${CMAKE_SOURCE_DIR}/include)
add_test(NAME LexerTest COMMAND test_lexer)