cmake_minimum_required(VERSION 3.14)
project(tesk VERSION 0.0.1 LANGUAGES C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_subdirectory(libs)

add_library(tesk 
    src/tesk/lexer/lexer.c
    src/tesk/lexer/token.c)
target_link_libraries(tesk vec_t strbld_t)
target_include_directories(tesk PUBLIC include)

enable_testing()
add_subdirectory(tests)