//
// Created by Gathrean Dela Cruz on 2023-11-16.
//

#pragma once

#include <vector>
#include "Room.hpp"

using namespace std;

/**
 * Default Maze Class
 */
class Maze : public Maze_Object {

private:

    /**
     * Vector of rooms
     */
    vector<Room *> rooms;

    /**
     * Vector of doors
     */
    vector<Door *> doors;

public:

    /**
     * Default Constructor
     */
    Maze() = default;

    /**
     * Room Adder
     * @pre: Room must be created
     * @post: Room is added to the maze
     * @return: none
     */
    void add_room(Room *room) {
        this->rooms.push_back(room);
    }

    /**
     * Door Adder
     * @pre: Door must be created
     * @post: Door is added to the maze
     * @return: none
     */
    void add_door(Door *door) {
        this->doors.push_back(door);
    }

    /**
     * Destructor for Maze class that de-allocates memory
     */
    virtual ~Maze() {
        for (auto room: this->rooms) {
            delete room;
        }
        for (auto door: this->doors) {
            delete door;
        }
    }
};

/**
 * Enchanted Fairy Land Maze class
 */
class Fairy_Maze : public Maze {

public:
    /**
     * Default Constructor for Fairy_Maze class
     */
    Fairy_Maze() = default;

    /**
     * Overridden print_description function
     */
    void print_description() override {
        cout << "A pretty, magical fairy maze" << endl;
    }
};

/**
* Futuristic Dystopian Maze class
*/
class Dystopian_Maze : public Maze {

public:
    /**
     * Default Constructor for Dystopian_Maze class
     */
    Dystopian_Maze() = default;

    /**
     * Overridden print_description function
     */
    void print_description() override {
        cout << "An Orwellian dystopian maze" << endl;
    }
};