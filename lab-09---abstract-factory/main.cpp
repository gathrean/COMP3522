//Name: Gathrean Dela Cruz
//Student# : A01167248

#include <iostream>

#include "Maze_Factory.hpp"
#include "Maze_Game.hpp"

int main() {
    // Create new factories for Fairy and Dystopian mazes
    Maze_Factory *p_Fairy_Factory = new Fairy_Maze_Factory;
    Maze_Factory *p_Dystopian_Factory = new Dystopian_Maze_Factory;

    // Create a new game
    Maze_Game game;

    // Create a Fairy maze and a Dystopian maze
    Maze *fairy_maze = game.create_maze(p_Fairy_Factory);
    cout << endl << endl;
    Maze *dystopian_maze = game.create_maze(p_Dystopian_Factory);

    // De-allocate the memory of the factories and the mazes
    delete p_Fairy_Factory;
    delete p_Dystopian_Factory;
    delete fairy_maze;
    delete dystopian_maze;

    // Exit the program
    return 0;
}
