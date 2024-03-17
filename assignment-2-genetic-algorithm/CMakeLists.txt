cmake_minimum_required(VERSION 3.20)
project(lab1template)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_STANDARD 20)

add_executable(assignment2template main.cpp
        Random_Generator.hpp
        Tour.hpp
        Population.hpp
        City.hpp
        Population.cpp
        City.cpp
        Random_Generator.cpp
        Tour.cpp
        SingletonFacade.hpp
        SingletonFacade.cpp)
