//
// Created by Gathrean Dela Cruz on 2023-09-12.
//

#include "readings.hpp"
#include "statistics.hpp"
#include "exporter.hpp"

#include <iostream>
#include <fstream> // using this for both writing and reading files
#include <random>
#include <iomanip>

using namespace std;

void generateRandomData(const char* filename) {
    ofstream outFile(filename);

    // return an error message if the file can't open
    if (!outFile.is_open()) {
        cerr << "Error: Could not open the file." << endl;
        return;
    }

    // From Week 2 Day 1 Lecture
    random_device rd;
    mt19937 generator(rd());

    // Range for int
    uniform_int_distribution<> intDistribution(minValue, maxValue);

    // Range for double
    uniform_real_distribution<double> doubleDistribution(minDouble, maxDouble);


//    int loopLimit = uniform_int_distribution<>(minValue, maxValue)(generator);

    int loopLimit = intDistribution(generator);


    for (int i = 0; i < loopLimit; ++i) {
        double myRandomDouble = doubleDistribution(generator);

        // Output with 3 decimal places to the file
        outFile << fixed << setprecision(3) << i << " " << myRandomDouble << endl;
    }

    outFile.close();
}

void analyzeReadings(const char* filename) {
    ifstream inFile(filename);

    if (!inFile.is_open()) {
        cerr << "Error: Could not open the file." << endl;
        return;
    }

    // Using maxValue constant variable from readings.hpp
    double readings[maxValue];
    int numReadings = 0;
    double sum = 0.0;

    // Read the values into the readings array and count them
    while (numReadings < maxValue && inFile >> readings[numReadings]) {
        sum += readings[numReadings];
        numReadings++;
    }

    double average = calculateAverage(sum, numReadings);
    double highest = findHighest(readings, numReadings);
    double lowest = findLowest(readings, numReadings);
    double median = calculateMedian(readings, numReadings);

    // sends the stats to exporter.cpp
    exportResults(numReadings, average, highest, lowest, median);

    inFile.close();
}