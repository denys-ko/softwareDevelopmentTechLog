cmake_minimum_required(VERSION 3.29)
project(lab C)

set(CMAKE_C_STANDARD 23)

add_executable(lab main.c)
target_link_libraries(lab m)
