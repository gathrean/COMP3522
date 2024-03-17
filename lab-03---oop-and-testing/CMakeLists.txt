cmake_minimum_required(VERSION 3.20)
project(lab3template)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_STANDARD 20)

add_executable(lab3template main.cpp catch.hpp
        myStack.hpp
        myStack.cpp
        unit_tests.cpp)
