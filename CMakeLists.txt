cmake_minimum_required(VERSION 3.30)
project(MessageQueue)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Include)

option(BUILD_EXAMPLES "" ON)

if (BUILD_EXAMPLES)
    add_subdirectory(Examples)
endif ()
