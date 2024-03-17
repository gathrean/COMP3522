//Name: Gathrean Dela Cruz
//Student# : A01167248

#include "readings.hpp"

int main() {
    const char* filename = "../Readings.txt";

    // Generate random data and write it to the file
    generateRandomData(filename);

    // Analyze the readings from the file
    analyzeReadings(filename);

    return 0;
}