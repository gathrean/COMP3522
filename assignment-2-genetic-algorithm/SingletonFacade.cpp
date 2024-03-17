//
// Created by Gathrean Dela Cruz on 2023-11-24.
//

#include "SingletonFacade.hpp"

void SingletonFacade::run() {

    // Welcome message to the traveling salesman
    // This is optional, but it's nice to have
    cout << "Welcome, Traveling Salesman!" << endl;
    cout << "This program will find the shortest path between 32 cities." << endl;

    cout << endl;
    cout << "There are " << CITIES_IN_TOUR << " cities in each simulation." << endl;
    cout << "There are " << POPULATION_SIZE << " candidate tours in our population." << endl;

    cout << endl;
    cout << "This program will iterate for " << ITERATIONS << " times." << endl;

    cout << endl;
    cout << "Would you like to begin? (y/n): ";

    char choice;
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        cout << endl << "Starting..." << endl << endl;
        perform_genetic_algorithm();
    } else if (choice == 'n' || choice == 'N') {
        cout << "Goodbye!" << endl;
        exit(0);
    } else {
        cout << "Invalid input. Goodbye!" << endl;
    }
}

void SingletonFacade::perform_genetic_algorithm() {
    int iteration_count = 0; // Iteration count
    double improvement = 0; // Improvement factor over original population
    double base_fitness; // Base fitness rating
    double current_fitness; // Current fitness rating

    // The Master List
    Population master_list(initialize_population()); // Create the original population (Can't be changed)
    base_fitness = master_list.get_elite_tour().get_fitness_rating(); // Set the first elite tour
    print_elite(master_list, false, 0); // Print the first elite and its city list

    // The Crossed List
    vector<Tour> crossed_list; // Create the crosses vector
    crossed_list.push_back(master_list.get_elite_tour()); // Move elite to front
    for (int i = 0; i < POPULATION_SIZE - 1; i++) {
        // Make the rest of the population
        crossed_list.push_back(crossover(master_list));
    }

    cout << "--- STARTING ALGORITHM ---" << endl;

    // The Chosen Tours List
    vector<Tour> chosen_tours = the_chosen_tours(crossed_list); // Select tours for mutation
    mutate(crossed_list, chosen_tours); // Perform mutation on the chosen tours
    Population result_list(crossed_list); // Create the result list

    // Genetic Algorithm
    for (int i = 0; i < ITERATIONS; i++) {
        // Perform crossover and mutation
        perform_crossover_and_mutation(i, crossed_list, result_list);

        // Calculate the improvement factor and display it
        current_fitness = result_list.get_elite_tour().get_fitness_rating();
        improvement = (base_fitness - current_fitness) / base_fitness * IMPROVEMENT_SCALAR;
        cout << "Improvement over base: " << improvement << "%" << endl;

        iteration_count++;
    }

    cout << endl << "--- FINISHED ALGORITHM ---" << endl;

    // Print the summary of the algorithm
    print_summary(master_list, result_list, iteration_count, improvement);
}

void SingletonFacade::perform_crossover_and_mutation(int iteration, vector<Tour> &crossed_list, Population &result_list) {
    // Move elite to front
    crossed_list.clear();
    crossed_list.push_back(result_list.get_elite_tour());

    // Perform crossover and mutation of tours
    for (int j = 0; j < POPULATION_SIZE - 1; j++) {
        Tour crossed_child = crossover(result_list);
        if (does_not_have_tour(crossed_list, crossed_child)) {
            crossed_list.push_back(crossed_child);
        } else {
            j--;
        }
    }

    // Display the iteration number and elite distance
    cout << endl;
    cout << "ITERATION: " << iteration + 1 << endl;
    cout << "Elite distance: " << crossed_list[0].get_fitness_rating() << endl;

    // Select tours for mutation and perform mutation
    mutate(crossed_list, the_chosen_tours(crossed_list));

    // Update population and elite tour
    result_list = Population(crossed_list); // Update result_list with crossed_list
    result_list.set_first_elite();
}

vector<Tour> SingletonFacade::initialize_population() {
    // Cities initialization
    vector<City> cities;
    for (int i = 0; i < CITIES_IN_TOUR; ++i) {
        City new_city(Random_Generator::random_coordinates(), Random_Generator::random_coordinates(), i);
        cities.push_back(new_city);
    }

    // Tours initialization
    vector<Tour> tours;
    for (int i = 0; i < POPULATION_SIZE; ++i) {
        Tour new_tour(cities);
        new_tour.determine_city_list();
        new_tour.determine_fitness();
        tours.push_back(new_tour);
    }

    // Return the vector of tours
    return tours;
}

void SingletonFacade::print_elite(Population &population, bool print_best, int iterations_count) {
    double elite_fitness = std::numeric_limits<double>::infinity();
    int elite_index = -1;

    for (int i = 0; i < population.size(); ++i) {
        if (population.get_tour(i).get_fitness_rating() < elite_fitness) {
            elite_fitness = population.get_tour(i).get_fitness_rating();
            elite_index = i;
        }
    }

    if (elite_index != -1) {
        if (print_best) {
            cout << "BEST ELITE (After " << iterations_count << " iterations)" << endl;
        } else {
            cout << "ORIGINAL ELITE" << endl;
        }

        cout << "Distance: " << elite_fitness << endl;

        const vector<City> &elite_city_list = population.get_tour(elite_index).get_cities_order();
        unsigned long numCities = elite_city_list.size();

        cout << "(City ";
        for (unsigned long i = 0; i < numCities; ++i) {
            cout << elite_city_list[i].get_sequence_number();
            if (i != numCities - 1) {
                cout << " -> City ";
            } else {
                cout << ")" << endl << endl;
            }
        }
    } else {
        if (print_best) {
            cout << "No best elite found." << endl;
        } else {
            cout << "No elite found in the initial population." << endl;
        }
    }
}

void SingletonFacade::print_summary(Population &master_list, Population &final_population, int iterations, double improvement) {
    cout << endl;
    cout << "Total iterations: " << iterations << endl << endl;

    print_elite(master_list, false, 0); // Print the first elite and its city list
    print_elite(final_population, true, iterations); // Print the best elite and its city list

    cout << "Improvement factor reached!" << endl;
    cout << "Improvement factor: " << improvement << "%" << endl;
}

vector<Tour> SingletonFacade::the_chosen_tours(vector<Tour> &crosses) {
    vector<Tour> chosen_tours;
    vector<Tour> already_picked;

    // Select a number of tours for mutation (random)
    int number_of_chosen_tours = Random_Generator::random_chosen_to_mutate();

    // Iterate through the number of chosen tours
    for (int i = 0; i < number_of_chosen_tours; i++) {
        // Get a random tour from the crosses vector
        int random_tour_picked = Random_Generator::random_tours();

        // If the random tour is not already in the chosen tours vector
        // Add the random tour to the already picked vector
        if (does_not_have_tour(already_picked, crosses[random_tour_picked])) {
            already_picked.push_back(crosses[random_tour_picked]);
            chosen_tours.push_back(crosses[random_tour_picked]);
        } else {
            i--;
        }
    }
    return chosen_tours;
}

vector<Tour> SingletonFacade::select_unique_parents(vector<Tour> &already_picked, Population &original_population) {
    vector<Tour> subset;

    // Select UNIQUE_PARENTS number of unique parents from the original population
    for (unsigned int i = 0; i < UNIQUE_PARENTS; i++) {
        // Get a random parent from the original population
        int random_parent = Random_Generator::random_tours();

        // If the random parent is not already in the subset
        // Add the random parent to the subset and already picked vectors
        if (does_not_have_tour(already_picked, original_population.get_tour_list()[random_parent])) {
            subset.push_back(original_population.get_tour_list()[random_parent]);
            already_picked.push_back(original_population.get_tour_list()[random_parent]);
        } else {
            i--;
        }
    }
    // Return the subset of unique parents
    return subset;
}

Tour SingletonFacade::crossover(Population &population) {
    // Vector to store tour indexes that have already been chosen
    vector<Tour> selected_tours;

    // Create a subset of unique parents from the original population
    Population first_subset(select_unique_parents(selected_tours, population));
    Population second_subset(select_unique_parents(selected_tours, population));

    // Get the elite Parents from the both subsets
    Tour parent1 = first_subset.get_elite_tour();
    Tour parent2 = second_subset.get_elite_tour();

    // Picking random index of parent 1
    vector<int> citiesList = parent1.get_cities_list();
    int random_index1 = citiesList[Random_Generator::random_cities()];

    // Place parent1 cities into child
    vector<City> child_cities = parent1.copy_parents(random_index1, parent1, parent2);

    // Create a child tour with the cities from parent1
    Tour child_tour(child_cities);
    child_tour.determine_fitness();

    // Return the child tour
    return child_tour;
}

void SingletonFacade::mutate(vector<Tour> &crosses, vector<Tour> chosen_tours) {
    // Iterate through the crosses vector
    for (unsigned int i = 1; i < crosses.size(); i++) {
        // If the chosenTours vector contains the current tour
        if (does_have_tour(chosen_tours, crosses[i])) {
            // Iterate through the cities in the current tour
            for (int j = 0; j < POPULATION_SIZE - 1; j++) {
                // If the random mutation chance is less than or equal to the mutation rate
                if (Random_Generator::random_mutation_chance() <= MUTATION_RATE) {
                    // Swap the current city with the next city
                    // (i.e., swap the current city with the next city in the tour)
                    swap(crosses[i].get_cities_list()[j], crosses[i].get_cities_list()[j + 1]);
                }
                // Determines the fitness of the current tour after mutation
                crosses[i].determine_fitness();
            }
        }
    }

}

bool SingletonFacade::has_tour(vector<Tour> &already_picked, const Tour &new_tour, bool condition) {
    for (const Tour &already_picked_tour: already_picked) {
        if (already_picked_tour.get_cities_list() == new_tour.get_cities_list()) {
            return condition;
        }
    }
    return !condition;
}