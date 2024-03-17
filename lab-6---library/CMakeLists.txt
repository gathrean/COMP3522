cmake_minimum_required(VERSION 3.20)
project(lab4template)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_STANDARD 20)

add_executable(lab4template
        main.cpp
        Book.hpp
        Library.cpp
        Library.hpp
        Catalogue.cpp
        Catalogue.hpp
        LibraryItem.hpp
        Journal.hpp
        DVD.hpp
        LibraryItemGenerator.hpp
        LibraryItemGenerator.cpp)
