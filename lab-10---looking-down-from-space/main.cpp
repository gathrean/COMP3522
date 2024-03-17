#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <chrono>
#include <thread>
#include "producer.hpp"
#include "consumer.hpp"

#include "location.hpp"

using namespace std;

vector<Location> readLocationsFromFile(const string &filePath) {
    vector<Location> locations;
    ifstream inputFile(filePath);

    if (!inputFile.is_open()) {
        cerr << "Unable to open file: " << filePath << endl;
        exit(-1);
    }

    string latitude, longitude;
    string line;

    while (getline(inputFile, line)) {
        if (line.empty()) {
            continue;
        }

        istringstream iss(line);
        string temp;
        vector<string> tokens;

        while (getline(iss, temp, '\t')) {
            tokens.push_back(temp);
        }

        if (tokens.size() >= 2) {
            latitude = to_string(stod(tokens[0]));
            longitude = to_string(stod(tokens[1]));

            locations.emplace_back(latitude, longitude);
        } else {
            cerr << "Error reading location data from file." << endl;
            exit(-1);
        }
    }

    inputFile.close();
    return locations;
}

int main() {
    //TODO The following are suggested comments to achieve the requirements
    //feel free to add/remove or differ if your intended solution is different


    //read latitude and longitude data from locations.txt or locations_test.txt
    vector<Location> locations = readLocationsFromFile("../locations.txt");

    //instantiate the shared CityInfoQueue used by producers and consumers
    CityInfoQueue cityInfoQueue;

    //create X number of producers
    // pass in a portion of the list of locations
    // pass in shared CityInfoQueue
    const int NUM_PRODUCERS = 3;
    const int LOCATIONS_PER_PRODUCER = locations.size() / NUM_PRODUCERS;

    vector<Producer> producers;
    for (int i = 0; i < NUM_PRODUCERS; ++i) {
        auto begin = locations.begin() + i * LOCATIONS_PER_PRODUCER;
        auto end = locations.begin() + (i + 1) * LOCATIONS_PER_PRODUCER;

        producers.emplace_back(vector<Location>(begin, end), cityInfoQueue);
    }

    //create Y number of consumers
    // pass in shared CityInfoQueue
    const int NUM_CONSUMERS = 2;
    vector<Consumer> consumersVec;
    for (int i = 0; i < NUM_CONSUMERS; ++i) {
        Consumer consumer(cityInfoQueue);
        consumersVec.emplace_back(consumer);
    }

    //start producer and consumer threads
    vector<thread> producerThreads;
    producerThreads.reserve(producers.size());
for (auto &producer: producers) {
        producerThreads.emplace_back(thread(producer));
    }

    vector<thread> consumerThreads;
    consumerThreads.reserve(consumersVec.size());
for (auto &consumer: consumersVec) {
        consumerThreads.emplace_back(thread(consumer));
    }

    // wait for producers to finish fetching data
    for (auto &thread: producerThreads) {
        thread.join();
    }

    //producers have finished fetching data now. Tell the CityInfoQueue that no more data will be added
    cityInfoQueue.setDataIncoming(false);

    //wait for consumers to finish consuming data
    for (auto &thread: consumerThreads) {
        thread.join();
    }

    return 0;
}

