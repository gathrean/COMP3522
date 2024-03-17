//
// Created by Gathrean Dela Cruz on 2023-11-23.
//

#include "Population.hpp"

void Population::set_first_elite() {
    // Iterate through the tours in the population.
    for (auto &tour: tour_list) {

        // Get the current fitness rating.
        double current_fitness_rating = tour.get_fitness_rating();

        // Swap the current tour with the first tour if it is more fit.
        if (current_fitness_rating < first_elite_distance) {
            first_elite_distance = current_fitness_rating;
            first_elite_cities = tour.get_cities_list();
            elite_tour = tour;

            // Move the Elite to the top.
            swap(tour_list[0], tour);
        }
    }
}