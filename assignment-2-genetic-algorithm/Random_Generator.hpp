//
// Created by Gathrean Dela Cruz on 2023-11-23.
//

#pragma once

#include <random>

using namespace std;

/**
 * Random_Generator Helper Class
 *
 * Meant to be used to randomly generate numbers for
 * certain scenarios in the Genetic Algorithm.
 */
class Random_Generator {
public:
    // Generates a random number between 0 and 1000 (inclusive).
    // PRE: None.
    // POST: Returns a random number between 0 and 1000 (inclusive).
    // RETURN: A random number between 0 and 1000 (inclusive).
    static int random_coordinates();

    // Generates a random number between 1 and 29 (inclusive).
    // PRE: None.
    // POST: Returns a random number between 1 and 29 (inclusive).
    // RETURN: A random number between 1 and 29 (inclusive).
    static int random_tours();

    // Generates a random number between 0 and 29 (inclusive).
    // PRE: None.
    // POST: Returns a random number between 0 and 29 (inclusive).
    // RETURN: A random number between 0 and 29 (inclusive).
    static int random_cities();

    // Generates a random number between 0 and 100 (inclusive).
    // PRE: None.
    // POST: Returns a random number between 0 and 100 (inclusive).
    // RETURN: A random number between 0 and 100 (inclusive).
    static int random_mutation_chance();

    // Generates a random number between 0 and 100 (inclusive).
    // PRE: None.
    // POST: Returns a random number between 0 and 100 (inclusive).
    // RETURN: A random number between 0 and 100 (inclusive).
    static int random_chosen_to_mutate();
};