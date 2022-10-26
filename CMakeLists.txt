cmake_minimum_required(VERSION 3.23)
project(projects C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(headers)

add_executable(projects
        fork-pipe.c)
