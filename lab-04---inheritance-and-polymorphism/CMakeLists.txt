cmake_minimum_required(VERSION 3.20)
project(lab4template)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_STANDARD 20)

add_executable(lab4template main.cpp
        inheritance.cpp
        animal.cpp
        animal.hpp
        bird.cpp
        bird.hpp
        canine.cpp
        canine.hpp)
