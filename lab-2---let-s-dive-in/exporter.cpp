//
// Created by Gathrean Dela Cruz on 2023-09-13.
//

#include "exporter.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

void exportResults(int numReadings, double average, double highest, double lowest, double median) {
    cout << "There are " << numReadings << " readings in the file. ";
    cout << "The average reading is " << fixed << setprecision(3) << average << "." << endl;
    cout << "The highest reading is " << fixed << setprecision(3) << highest << "." << endl;
    cout << "The lowest reading is " << fixed << setprecision(3) << lowest << "." << endl;
    cout << "The median reading is " << fixed << setprecision(3) << median << "." << endl;
}