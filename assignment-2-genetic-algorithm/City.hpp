//
// Created by Gathrean Dela Cruz on 2023-11-23.
//

#pragma once

#include <vector>
#include "Random_Generator.hpp"

/**
 * @brief City class that holds the coordinates of a city.
 */
class City {

private:
    // x coordinate of the city.
    int x_coordinate;

    // y coordinate of the city.
    int y_coordinate;

    // A sequence number that is assigned to each city.
    int sequence_number;

public:

    // The maximum coordinate value.
    static const int MAX_COORDINATE = 1000;

    // Default constructor for the City class.
    // PRE: None.
    // POST: Initializes a City object with default values.
    // RETURN: None.
    City() = default;

    // Constructor for the City class.
    City(int xCoord, int yCoord, int seqNum) : x_coordinate(xCoord), y_coordinate(yCoord), sequence_number(seqNum) {}

    // Getter method for the x coordinate.
    // PRE: None.
    // POST: Returns the x coordinate.
    // RETURN: An integer representing the x coordinate of the city.
    inline int get_x_coordinate() const { return x_coordinate; }

    // Getter method for the y coordinate.
    // PRE: None.
    // POST: Returns the y coordinate.
    // RETURN: An integer representing the y coordinate of the city.
    inline int get_y_coordinate() const { return y_coordinate; }

    // Getter method for the sequence number.
    // PRE: None.
    // POST: Returns the sequence number.
    // RETURN: An integer representing the sequence number of the city.
    inline int get_sequence_number() const { return sequence_number; }
};