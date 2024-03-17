//
// Created by Gathrean Dela Cruz on 2023-11-16.
//

#pragma once

#include "Maze_Factory.hpp"

class Maze_Game {

public:
    // a method create_maze that accepts a reference to a maze factory and uses the maze_factory to make a maze.
    // the create_maze method returns a pointer to the newly created maze.

    /**
     * Creates a maze from the factory
     * @pre - factory - a pointer to a Maze_Factory
     * @post - none
     * @return - a pointer to a Maze
     */
    Maze *create_maze(Maze_Factory *factory) {

        // Creating a maze from the factory
        Maze *maze = factory->make_maze();

        // Creating two rooms from the factory
        Room *room1 = factory->make_room();
        Room *room2 = factory->make_room();

        // Adding the doors to the rooms
        Door *door = factory->make_door(room1, room2);
        room1->add_door(door);
        room2->add_door(door);

        // Adding walls to the rooms
        Wall *wall = nullptr;
        for (int i = 0; i < 4; i++) {
            wall = factory->make_wall();
            room1->add_wall(wall);
        }
        for (int i = 0; i < 4; i++) {
            wall = factory->make_wall();
            room2->add_wall(wall);
        }

        maze->add_room(room1);
        maze->add_room(room2);
        maze->add_door(door);

        maze->print_description();
        door->print_description();

        std::cout << "Room 1: ";
        room1->print_description();
        std::cout << "Room 2: ";
        room2->print_description();

        return maze;
    }
};
