//
// Created by Gathrean Dela Cruz on 2023-11-24.
//

#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

#include "City.hpp"
#include "Population.hpp"
#include "Random_Generator.hpp"

using namespace std;

class SingletonFacade {

private:
    // The number of cities in each simulation.
    static const int CITIES_IN_TOUR = 32;

    // The number of candidate tours in our population
    static const int POPULATION_SIZE = 32;

    // The maximum number of times the algorithm should iterate (maybe 1000)
    static const int ITERATIONS = 50;

    // Scalar to convert improvement to percentage
    static const int IMPROVEMENT_SCALAR = 10;

    // The number of parents to select for crossover
    static const int UNIQUE_PARENTS = 5;

    // The rate at which mutation should occur
    static const int MUTATION_RATE = 15;

public:
    // Static method to get the instance of the SingletonFacade
    inline static SingletonFacade &get_instance() {
        static SingletonFacade instance;
        return instance;
    }

    // Method to start the program. Follows the Genetic Algorithm
    // PRE: None.
    // POST: Starts the program.
    // RETURN: None.
    static void run();

private:
    // Private constructor for Singleton pattern
    SingletonFacade() = default;

    // Initializes the population of tours around the cities.
    // PRE: None.
    // POST: Initializes a population of tours around the cities.
    // RETURN: A vector of tours.
    static vector<Tour> initialize_population();

    // Method to perform the Genetic Algorithm.
    // PRE: None.
    // POST: Performs the Genetic Algorithm.
    // RETURN: None.
    static void perform_genetic_algorithm();

    // Method to perform the Genetic Algorithm, to be used in run() method.
    // PRE: None.
    // POST: Performs the Genetic Algorithm.
    // RETURN: None.
    static void perform_crossover_and_mutation(int iteration, vector<Tour> &crossed_list, Population &result_list);

    // Method to print the elite tours in a population.
    // PRE: population must be populated with Tour objects.
    // POST: Outputs the elite tours in the population to the console.
    // RETURN: None.
    static void print_elite(Population &population, bool print_best, int iterations_count);

    // Method to print the summary of the algorithm.
    // PRE: masterList must be populated with Tour objects.
    // POST: Outputs the summary of the algorithm to the console.
    // RETURN: None.
    static void print_summary(Population &master_list, Population &final_population, int iterations, double improvement);

    // Method to select a number of tours for mutation.
    // PRE: crosses must contain valid Tour objects.
    // POST: Returns a subset of the crosses vector based on a random selection.
    static vector<Tour> the_chosen_tours(vector<Tour> &crosses);

    // Method to select the parents for a new tour from a population
    // PRE: already_picked must be a vector of Tour objects; original_population must be a valid Population object.
    // POST: Selects two unique parents from the original population and returns them in a vector.
    // RETURN: A vector of Tour objects representing the parents.
    static vector<Tour> select_unique_parents(vector<Tour> &already_picked, Population &original_population);

    // Method to create a new tour from a given set of parent tours
    // PRE: parent1 and parent2 should be valid Tour objects; randomIndex1 should be within the range of cityList indexes.
    // POST: Creates a new tour by combining cities from parent1 and parent2 without duplicating cities.
    // RETURN: A vector of City objects representing the new tour.
    static Tour crossover(Population &original_population);

    // Method to mutate a set of tours by swapping two cities in each tour.
    // PRE: The crosses and chosenTours vectors must contain valid Tour objects.
    // POST: Performs mutation on chosen tours within the crosses vector.
    // RETURN: None.
    static void mutate(vector<Tour> &crosses, vector<Tour> chosen_tours);

    // Method to check if a given tour is already in a vector of tours.
    // PRE: already_picked must be a vector of Tour objects; tour is the Tour object to check; condition is a boolean
    //     representing whether the method should check if the tour is in the vector or not.
    // POST: Iterates through the alreadyPicked vector and checks if any tour has the same fitness rating as
    //       the given tour.
    // RETURN: Returns true if the tour is found (i.e., has the same fitness rating as any tour in the vector),
    static bool has_tour(vector<Tour> &already_picked, const Tour &new_tour, bool condition);

    // Method to check if a given tour is not already in a vector of tours.
    // PRE: already_picked must be a vector of Tour objects; tour is the Tour object to check.
    // POST: Iterates through the alreadyPicked vector and checks if any tour has the same fitness rating as
    //       the given tour.
    // RETURN: Returns true if the tour is not found (i.e., does not have the same fitness rating as any tour in the vector),
    //         false otherwise.
    static bool does_not_have_tour(vector<Tour> &already_picked, const Tour &new_tour) {
        return has_tour(already_picked, new_tour, false);
    }

    // Method to check if a given tour is already in a vector of tours.
    // PRE: already_picked must be a vector of Tour objects; tour is the Tour object to check.
    // POST: Iterates through the alreadyPicked vector and checks if any tour has the same fitness rating
    //       as the given tour.
    // RETURN: Returns true if the tour is found (i.e., has the same fitness rating as any tour in the vector),
    //         false otherwise.
    static bool does_have_tour(vector<Tour> &already_picked, const Tour &tour) {
        return has_tour(already_picked, tour, true);
    }

public:

    // Copy constructor for the SingletonFacade class
    // This is deleted to prevent copying of the SingletonFacade instance
    SingletonFacade(SingletonFacade const &) = delete;

    // Copy assignment operator for the SingletonFacade class
    // This is deleted to prevent assignment of the SingletonFacade instance to another.
    void operator=(SingletonFacade const &) = delete;
};
