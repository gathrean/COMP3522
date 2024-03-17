//
// Created by Gathrean Dela Cruz on 2023-09-13.
//

#include "statistics.hpp"

double calculateAverage(double sum, double numReadings){
    return sum / numReadings;
}

double findHighest(const double* readings, int numReadings) {
    if (numReadings <= 0) {
        return -1; // like returning invalid result
    }

    // Initialize with the first element
    double highest = readings[0];

    for (int i = 1; i < numReadings; i++) {
        if (readings[i] > highest) {
            highest = readings[i];
        }
    }

    return highest;
}

double findLowest(const double* readings, int numReadings) {
    if (numReadings <= 0) {
        return -1; // like returning invalid result
    }

    // Initialize with the first element, because it would mostly be the lowest
    double lowest = readings[0];

    for (int i = 1; i < numReadings; i++) {
        if (readings[i] < lowest) {
            lowest = readings[i];
        }
    }

    return lowest;
}

double calculateMedian(const double readings[], int numReadings) {
    if (numReadings % 2 == 0) {
        int mid1 = numReadings / 2 - 1;
        int mid2 = numReadings / 2;
        return (readings[mid1] + readings[mid2]) / 2.0;
    } else {
        int mid = numReadings / 2;
        return readings[mid];
    }
}