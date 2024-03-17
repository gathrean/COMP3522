//
// Created by Gathrean Dela Cruz on 2023-11-23.
//

#include <vector>
#include <iostream>
#include "City.hpp"

#pragma once

using namespace std;

/**
 * Tour Class
 *
 * - A tour is a list of cities.
 * - Contains a list of all the cities in the simulation and a fitness rating.
 * - The fitness rating evaluates the distance the traveling salesman would
 *   need to travel to visit the cities in the order they appear.
 */
class Tour {

private:
    // The fitness rating of the tour.
    // Shorter tours are better quality, and will have better fitness ratings.
    double fitness_rating{0};

    // The list of cities in the tour.
    vector<City> city_list;

public:
    // Default constructor
    Tour() = default;

    // Constructor that takes a list of cities and shuffling them to create a tour.
    explicit Tour(vector<City> city_list) : city_list(city_list) {};

    // Getter method for fitness
    double get_fitness_rating() const { return fitness_rating; }

    // Determines the fitness rating for the tour using the Euclidean distance.
    // PRE: cityList must be populated with City objects.
    // POST: Calculates the total Euclidean distance between consecutive cities in the tour and updates fitnessRating.
    // RETURN: None.
    void determine_fitness();

    // Shuffles the cities in the city list.
    // PRE: cityList must be populated with City objects.
    // POST: Randomly shuffles the order of cities in cityList to create a new tour permutation.
    // RETURN: None.
    void determine_city_list();

    // Getter method for the sequence numbers of cities in the tour.
    // PRE: cityList must be populated with City objects.
    // POST: Retrieves and returns the sequence numbers of cities in the tour.
    // RETURN: A vector of integers representing the sequence numbers of cities in the tour.
    vector<int> get_cities_list() const;

    // Getter method for the order of cities in the tour.
    // (Will be used to properly print the order of cities in an elite tour).
    // PRE: cityList must be populated with City objects.
    // POST: Retrieves and returns the order of cities in an elite tour.
    // RETURN: A const reference to a vector of City objects representing the order of cities in an elite tour.
    inline const vector<City> &get_cities_order() const { return city_list; }

    inline void add_city(const City &city) { city_list.push_back(city); }

    vector<City> copy_parents(int &random_index1, Tour &parent1, Tour &parent2);

    static bool does_not_have_city(vector<int> &already_checked_cities, int new_city);

    // getter method for the tour
    inline vector<City> get_tour() const { return city_list; }
};
