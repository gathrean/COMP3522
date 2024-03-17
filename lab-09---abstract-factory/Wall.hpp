//
// Created by Gathrean Dela Cruz on 2023-11-16.
//

#pragma once

#include <iostream>
#include "Maze_Object.hpp"

using namespace std;

/**
 * Default Wall class
 */
class Wall : public Maze_Object {

public:
    /**
     * Default constructor
     */
    Wall() = default;

    /**
     * Overloaded insertion operator
     * @pre ostream reference
     * @pre Wall reference
     * @post Wall is printed
     * @return ostream reference
     */
    friend ostream &operator<<(ostream &os, const Wall &wall) {
        os << "Wall";
        return os;
    }
};

/**
 * Enchanted Fairy Land Wall
 * Concrete Child Class
 */
class Fairy_Wall : public Wall {

public:
    /**
     * Default constructor
     */
    Fairy_Wall() {}

    /**
     * Description Printer
     * @pre - none
     * @post - none
     * @return - none
     */
    void print_description() override {
        cout << "This wall has fairy wings on it" << endl;
    }
};

/**
 * Futuristic Dystopian Wall
 * Concrete Child Class
 */
class Dystopian_Wall : public Wall {

public:
    /**
     * Default constructor
     */
    Dystopian_Wall() {}

    /**
     * Description Printer
     * @pre - none
     * @post - none
     * @return - none
     */
    void print_description() override {
        cout << "This wall has surveillance cameras on it" << endl;
    }
};