//
// Created by Gathrean Dela Cruz on 2023-11-23.
//

#pragma once

#include "Tour.hpp"

using namespace std;

class Population {
    // the distance of the first elite
    constexpr static double ELITE_DISTANCE = 999999;

private:
    // The distance of the first elite.
    double first_elite_distance{ELITE_DISTANCE};

    // A vector to store the sequence numbers of cities in the first elite tour.
    vector<int> first_elite_cities;

    // The list of tours in the population.
    vector<Tour> tour_list;

    // The fittest tour in the population.
    Tour elite_tour;

public:
    // Population Constructor that takes a list of tours.
    // PRE: tours must be a vector of Tour objects.
    // POST: Initializes a Population object with the provided list of Tour objects and sets the first elite tour.
    // RETURN: None. (Constructor)
    explicit Population(vector<Tour> tours) : tour_list(std::move(tours)) { set_first_elite(); }

    // Method to set the first elite tour based on the fitness rating.
    // PRE: tours must be populated with Tour objects.
    // POST: Finds the tour with the lowest fitness rating and sets it as the elite tour along with its distance and cities.
    // RETURN: None.
    void set_first_elite();

    // Getter method for the fittest tour
    // PRE: fittestTour must be a valid Tour object.
    // POST: Returns the fittest tour.
    // RETURN: A Tour object.
    inline Tour &get_elite_tour() { return elite_tour; }

    // Getter method for the list of tours
    // PRE: tours must be populated with Tour objects.
    // POST: Returns the list of tours.
    // RETURN: A vector of Tour objects.
    inline vector<Tour> get_tour_list() { return tour_list; }

    // Getter method for a specific Tour
    // PRE: index must be a valid index in the population.
    // POST: Returns the tour at the specified index.
    // RETURN: A Tour object.
    Tour &get_tour(int index) { return tour_list[index]; }

    // size() method:
    int size() { return tour_list.size(); }

    //get population:
    vector<Tour> get_population() { return tour_list; }
};