//
// Created by Gathrean Dela Cruz on 2023-11-16.
//

#pragma once

#include "Maze.hpp"
#include "Wall.hpp"
#include "Room.hpp"
#include "Door.hpp"

/**
 * Default Maze Factory class
 */
class Maze_Factory {

public:
    /**
     * Maze Maker
     * @pre - none
     * @post - none
     * @return - a new Maze
     */
    virtual Maze *make_maze() = 0;

    /**
     * Wall Maker
     * @pre - none
     * @post - none
     * @return - a new Wall
     */
    virtual Wall *make_wall() = 0;

    /**
     * Room Maker
     * @pre - none
     * @post - none
     * @return - a new Room
     */
    virtual Room *make_room() = 0;

    /**
     * Door Maker
     * @pre - room1 - a pointer to a Room
     * @pre - room2 - a pointer to a Room
     * @post - none
     * @return - a new Door that connects room1 and room2
     */
    virtual Door *make_door(Room *room1, Room *room2) = 0;

    ~Maze_Factory() = default;
};

/**
 * Enchanted Fairy Land Maze class
 * Concrete Child Class of Maze_Factory
 */
class Fairy_Maze_Factory : public Maze_Factory {

public:
    /**
     * Fairy Maze Factory Constructor
     */
    Fairy_Maze_Factory() = default;

    /**
     * Fairy Maze Maker
     * @pre - none
     * @post - none
     * @return - a new Fairy Maze
     */
    Maze *make_maze() override {
        return new Fairy_Maze;
    }

    /**
     * Fairy Wall Maker
     * @pre - none
     * @post - none
     * @return - a new Fairy Wall
     */
    Wall *make_wall() override {
        return new Fairy_Wall;
    }

    /**
     * Fairy Room Maker
     * @pre - none
     * @post - none
     * @return - a new Fairy Room
     */
    Room *make_room() override {
        return new Fairy_Room;
    }

    /**
     * Fairy Door Maker
     * @pre - room1 - a pointer to a Room
     * @pre - room2 - a pointer to a Room
     * @post - none
     * @return - a new Fairy Door that connects room1 and room2
     */
    Door *make_door(Room *room1, Room *room2) override {
        Door *door = new Fairy_Door;
        room1->add_door(door);
        room2->add_door(door);
        return door;
    }
};

/**
 * Futuristic Dystopian Maze class
 * Concrete Child Class of Maze_Factory
 */
class Dystopian_Maze_Factory : public Maze_Factory {

public:
    /**
     * Dystopian Maze Factory Constructor
     */
    Dystopian_Maze_Factory() = default;

    /**
     * Dystopian Maze Maker
     * @pre - none
     * @post - none
     * @return - a new Dystopian Maze
     */
    Maze *make_maze() override {
        return new Dystopian_Maze;
    }

    /**
     * Dystopian Wall Maker
     * @pre - none
     * @post - none
     * @return - a new Dystopian Wall
     */
    Wall *make_wall() override {
        return new Dystopian_Wall;
    }

    /**
     * Dystopian Room Maker
     * @pre - none
     * @post - none
     * @return - a new Dystopian Room
     */
    Room *make_room() override {
        return new Dystopian_Room;
    }

    /**
     * Dystopian Door Maker
     * @pre - room1 - a pointer to a Room
     * @pre - room2 - a pointer to a Room
     * @post - none
     * @return - a new Dystopian Door that connects room1 and room2
     */
    Door *make_door(Room *room1, Room *room2) override {
        Door *door = new Dystopian_Door;
        room1->add_door(door);
        room2->add_door(door);
        return door;
    }
};
