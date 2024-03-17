//
// Created by Gathrean Dela Cruz on 2023-11-23.
//

#include "Tour.hpp"

void Tour::determine_fitness() {
    long xDiff;
    long yDiff;

    for (unsigned int i = 0; i < city_list.size() - 1; i++) {
        xDiff = (city_list[i].get_x_coordinate() - city_list[i + 1].get_x_coordinate());
        yDiff = (city_list[i].get_y_coordinate() - city_list[i + 1].get_y_coordinate());

        fitness_rating += sqrt((xDiff * xDiff) + (yDiff * yDiff));
    }
}

void Tour::determine_city_list() {
    random_device rd;
    mt19937 gen(rd());
    shuffle(city_list.begin(), city_list.end(), gen);
}

vector<int> Tour::get_cities_list() const {
    vector<int> cities;
    for (const City &city: city_list) {
        cities.push_back(city.get_sequence_number());
    }
    return cities;
}

vector<City> Tour::copy_parents(int &random_index1, Tour &parent1, Tour &parent2) {
    vector<City> child;
    vector<int> already_checked;

    for (int i = 0; i <= random_index1; i++) {
        child.push_back(parent1.city_list[i]);
        already_checked.push_back(parent1.city_list[i].get_sequence_number());
    }

    for (unsigned int i = 0; i < parent2.city_list.size(); i++) {
        // Check if the sequence number is not in the already_checked vector
        if (does_not_have_city(already_checked, parent2.city_list[i].get_sequence_number())) {
            // If not found, it's safe to add the city from parent2 to the child
            child.push_back(parent2.city_list[i]);
            already_checked.push_back(parent2.city_list[i].get_sequence_number());
        }
    }

    return child;
}

bool Tour::does_not_have_city(vector<int> &already_checked_cities, int new_city) {

    for (unsigned long i = 0; i < already_checked_cities.size(); i++) {

        if (already_checked_cities[i] == new_city) {
            return false;
        }
    }
    return true;
}