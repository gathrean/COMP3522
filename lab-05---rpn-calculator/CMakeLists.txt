cmake_minimum_required(VERSION 3.20)
project(lab1template)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_STANDARD 20)

add_executable(lab5template main.cpp
        operation.hpp
        abstract_operation.hpp
        addition_operation.hpp
        subtraction_operation.hpp
        multiplication_operation.hpp
        division_operation.hpp
        rpn_calculator.hpp
        rpn_calculator.cpp)
