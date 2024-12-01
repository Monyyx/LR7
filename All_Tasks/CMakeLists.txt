cmake_minimum_required(VERSION 3.10ё)
project(LR7)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,undefined,leak -fno-omit-frame-pointer")
set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fsanitize=address,undefined,leak")


set(CMAKE_CXX_COMPILER "g++")

add_executable(LR7
        LR7.cpp
        func_1.cpp
        func_1.h
        func_2.cpp
        func_2.h
        func_3.cpp
        func_3.h
        func_4.cpp
        func_4.h
        func_5.cpp
        func_5.h
)
