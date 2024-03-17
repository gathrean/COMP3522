//
// Created by Gathrean Dela Cruz on 2023-11-23.
//

#include "Random_Generator.hpp"

int Random_Generator::random_coordinates() {
    // Coordinate constants
    const int MIN_COORDINATE = 0;
    const int MAX_COORDINATE = 1000;

    // Random number generator.
    random_device rd;
    mt19937 mt(rd()); // "Mersenne Twister pseudo-random generator of 32-bit numbers with a state size of 19937 bits."

    // Picks a random number between 0 and 1000 (inclusive)
    uniform_int_distribution<int> distribution(MIN_COORDINATE, MAX_COORDINATE);

    return distribution(mt);
}

int Random_Generator::random_tours() {
    // Tour constants
    const int MIN_CHOICE = 1;
    const int MAX_CHOICE = 29;

    // Random number generator.
    random_device rd;
    mt19937 mt(rd());

    // Picks a random tour from index 1 to 29 (inclusive)
    uniform_int_distribution<int> distribution(MIN_CHOICE, MAX_CHOICE);

    return distribution(mt);
}

int Random_Generator::random_cities() {
    // City constants
    const int MIN_CITY = 0;
    const int MAX_CITY = 29;

    // Random number generator.
    random_device rd;
    mt19937 mt(rd());

    // Picks a random city from index 0 to 29 (inclusive)
    uniform_int_distribution<int> distribution(MIN_CITY, MAX_CITY);

    // Returns a random city from index 0 to 29 (inclusive)
    return distribution(mt);
}

int Random_Generator::random_mutation_chance() {
    // Mutation constants
    const int MIN_MUTATION_CHANCE = 0;
    const int MAX_MUTATION_CHANCE = 100;

    // Random number generator.
    random_device rd;
    mt19937 mt(rd());

    // Picks a random mutation chance from 0 to 100 (inclusive)
    uniform_int_distribution<int> distribution(MIN_MUTATION_CHANCE, MAX_MUTATION_CHANCE);

    // Returns a random mutation chance from 0 to 100 (inclusive)
    return distribution(mt);
}

int Random_Generator::random_chosen_to_mutate() {
    // Mutation constants
    const int numberOfCities = 30;
    const int MIN_CHOSEN = numberOfCities * 0.2;
    const int MAX_CHOSEN = numberOfCities * 0.3;

    // Random number generator.
    random_device rd;
    mt19937 mt(rd());

    // Picks a random number of tours to mutate from 6 to 9 (inclusive)
    uniform_int_distribution<int> distribution(MIN_CHOSEN, MAX_CHOSEN);

    // Returns a random number of tours to mutate from 6 to 9 (inclusive)
    return distribution(mt);
}