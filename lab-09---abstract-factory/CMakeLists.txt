cmake_minimum_required(VERSION 3.20)
project(lab1template)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_STANDARD 20)

add_executable(lab9template
        main.cpp
        Maze_Game.hpp
        Door.hpp
        Maze_Factory.hpp
        Room.hpp
        Wall.hpp
        Maze.hpp
        Maze_Object.hpp
)
