//
// Created by Gathrean Dela Cruz on 2023-11-16.
//

#pragma once

#include "Wall.hpp"
#include "Door.hpp"
#include "Maze_Object.hpp"
#include <vector>

/**
 * Default Room class
 */
class Room : public Maze_Object {

protected:

    /**
     * Vector of pointers to the room's walls
     */
    vector<Wall *> walls;

    /**
     * Pointer to the room's door
     */
    Door *door = nullptr;

public:

    /**
     * Default constructor
     * @pre - wall - a pointer to a Wall
     * @post - pushes a wall into the vector
     * @return - none
     */
    void add_wall(Wall *wall) {
        this->walls.push_back(wall);
    }

    /**
     * Add a door to the room
     * @pre - door - a pointer to a Door
     * @post - pushes a door into the vector
     * @return - none
     */
    void add_door(Door *door) {
        this->door = door;
    }

    /**
     * Virtual destructor for Room class that de-allocates memory of each wall
     */
    virtual ~Room() {
        for (auto wall: this->walls) {
            delete wall;
        }
    }

};

/**
 * Enchanted Fairy Land Room class
 */
class Fairy_Room : public Room {
public:
    /**
     * Fairy Room constructor
     */
    Fairy_Room() = default;

    /**
     * Print the description of the room
     * @pre - none
     * @post - none
     * @return - a string of the description
     */
    void print_description() override {
        cout << "This room has fairies in it" << endl;
        for (int i = 0; i < (int) this->walls.size(); i++) {
            this->walls[i]->print_description();
        }
    }
};

/**
 * Futuristic Dystopian Room class
 */
class Dystopian_Room : public Room {
public:
    /**
     * Dystopian Room constructor
     */
    Dystopian_Room() = default;

    /**
     * Print the description of the room
     * @pre - none
     * @post - none
     * @return - a string of the description
     */
    void print_description() override {
        cout << "This room is run down and cracked" << endl;
        for (int i = 0; i < (int) this->walls.size(); i++) {
            this->walls[i]->print_description();
        }
    }
};