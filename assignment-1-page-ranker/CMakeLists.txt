cmake_minimum_required(VERSION 3.20)
project(lab1template)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_STANDARD 20)

add_executable(assignment1template main.cpp
        Matrix.cpp
        Matrix.hpp
        MatrixBuilder.cpp
        MatrixBuilder.hpp
        PageRanker.cpp
        PageRanker.hpp)
