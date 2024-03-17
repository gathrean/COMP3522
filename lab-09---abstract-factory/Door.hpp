//
// Created by Gathrean Dela Cruz on 2023-11-16.
//

#pragma once

#include "Room.hpp"
#include "Maze_Object.hpp"

// Forward declaration of Room
class Room;

/**
 * Default Door class
 */
class Door : public Maze_Object {

private:
    /**
     * The first room
     */
    Room *room1 = nullptr;

    /**
     * The second room
     */
    Room *room2 = nullptr;

public:
    /**
     * Default constructor
     */
    Door() = default;

    /**
     * Add the first room
     * @pre r1 - a pointer to a Room
     * @post - none
     * @return - none
     */
    virtual void addRoom1(Room *room) {
        this->room1 = room;
    }

    /**
     * Add the second room
     * @pre r2 - a pointer to a Room
     * @post - none
     * @return - none
     */
    virtual void addRoom2(Room *room) {
        this->room2 = room;
    }
};

/**
 * Enchanted Fairy Land Door class
 * Concrete Child Class
 */
class Fairy_Door : public Door {

public:
    /**
     * Fairy Door constructor
     * @pre - none
     * @post - none
     * @return - none
     */
    Fairy_Door() : Door() {}

    /**
     * Print the description of the door
     * @pre - none
     * @post - none
     * @return - none
     */
    void print_description() override {
        cout << "This door has a fairy wing for a handle." << endl
             << "This door connects fairy Room 0 and fairy Room 1"
             << endl;
    }
};

/**
 * Futuristic Dystopian Door class
 * Concrete Child Class
 */
class Dystopian_Door : public Door {

public:

    /**
     * Dystopian Door constructor
     * @pre - none
     * @post - none
     * @return - none
     */
    Dystopian_Door() : Door() {}

    /**
     * Print the description of the door
     * @pre - none
     * @post - none
     * @return - none
     */
    void print_description() override {
        cout << "This door has a fingerprint scanner for a handle." << endl
             << "This door connects dystopian Room 0 and dystopian Room 1"
             << endl;
    }
};