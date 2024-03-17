//Student Name: Gathrean Dela Cruz
//Student Number: A01167248

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "bidder.hpp"
#include "auction.hpp"

using namespace std;

/**
 * Random Number Generator
 * PRE: min is the lower bound of the random number range
 * PRE: max is the upper bound of the random number range
 * POST: min and max are unchanged
 * RETURN: a pseudo-random floating point number between min and max
 */
double generate_random(double min, double max) {
    double f = (double) rand() / RAND_MAX;
    return min + f * (max - min);
}

/**
 * Menu
 * PRE: bidders is a vector of pointers to Bidder objects
 * PRE: item is the name of the auction item
 * PRE: start_price is the starting price of the item
 * POST: The auction is executed or new bidders are added based on user input
 * FUNCTION: Displays the auction menu and handles user interaction
 */
void menu(vector<Bidder *> & bidders, string item, double start_price) {
    int option;

    cout << endl;
    cout << "Welcome!!" << endl;
    cout << "------------------" << endl;
    cout << "Here are your choices:" << endl;
    cout << "1. Start Auction" << endl;
    cout << "2. Add More Bidders" << endl;
    cout << "3. Exit" << endl;
    cout << "------------------" << endl;
    cout << "Choose an option (1-3): ";

    cin >> option;
    cin.ignore(); // Consume the newline character left in the buffer

    if (option == 1) {
        cout << endl;
        cout << "Starting Auction!!" << endl;
        cout << "------------------" << endl;
        Auction my_auction(bidders);
        my_auction.simulate_auction(item, start_price);
    } else if (option == 2) {
        cout << "Do you want to add more bidders? (yes/no): ";
        string choice;
        cin >> choice;

        cin.ignore(); // Consume the newline character left in the buffer

        // Extra UI if the user wants to add a bidder
        while (choice == "yes") {
            cout << "Enter bidder name: ";
            string name;
            getline(cin, name);

            cout << "Enter bidder budget: ";
            double budget;
            cin >> budget;

            cin.ignore();

            cout << "Enter bidder bid probability (between 0 and 1): ";
            double bidProbability;
            cin >> bidProbability;

            cin.ignore();

            cout << "Enter bidder bid increase percentage (greater than 1): ";
            double bidIncreasePercentage;
            cin >> bidIncreasePercentage;

            cin.ignore();

            bidders.push_back(new Bidder(name, budget, bidProbability, bidIncreasePercentage));

            cout << "Do you want to add more bidders? (yes/no): ";
            cin >> choice;

            cin.ignore();
        }
    } else if (option == 3) {
        cout << "Exiting the program." << endl;
        exit(0);
    } else {
        cout << "Invalid option. Please choose a valid option." << endl;
    }
}

/**
 * Start
 * PRE: bidders is a vector of pointers to Bidder objects
 * FUNCTION: Initializes the auction by getting the item and starting price, then calls the menu
 * POST: The auction is executed or new bidders are added based on user input
 * RETURN: None
 */
void start(vector<Bidder *> & bidders) {
    string item_name;
    double start_price;

    cout << "Enter the name of the item being auctioned: ";
    getline(cin, item_name);

    cout << "Enter the starting price: ";
    cin >> start_price;

    cin.ignore(); // Consume the newline character left in the buffer

    menu(bidders, item_name, start_price);
}

/**
 * Main
 * PRE: None
 * POST: The auction is executed or new bidders are added based on user input
 * RETURN: 0
 */
int main() {
    vector<Bidder *> bidders;
    const double MIN_BID = 0;
    const double MAX_BID = 100;
    srand(time(0));

    // Hard-coding the initial bidders.
    bidders.push_back(new Bidder("Jojo", 3000, generate_random(MIN_BID, MAX_BID), 1.2));
    bidders.push_back(new Bidder("Melissa", 7000, generate_random(MIN_BID, MAX_BID), 1.5));
    bidders.push_back(new Bidder("Priya", 15000, generate_random(MIN_BID, MAX_BID), 1.1));
    bidders.push_back(new Bidder("Kewei", 800, generate_random(MIN_BID, MAX_BID), 1.9));
    bidders.push_back(new Bidder("Scott", 4000, generate_random(MIN_BID, MAX_BID), 2));

    // Start the auction
    start(bidders);

    // Free allocated memory for bidders
    for (Bidder * bidder: bidders) { delete bidder; }

    return 0;
}