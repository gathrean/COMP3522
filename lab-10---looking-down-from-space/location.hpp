//
// Created by jyim3 on 2023-08-16.
//

#ifndef LABSPACETEMPLATE_LOCATION_HPP
#define LABSPACETEMPLATE_LOCATION_HPP

#include "iostream"

using namespace std;

/*
 * Latitude and longitude information representing a location in the world
 * No need to add code, but you may if needed
 */
struct Location {
    string latitude;
    string longitude;

    // Constructor for location
    // PRE: latitude - the latitude coordinate for location
    // PRE: longitude - the longitude coordinate for location
    // RETURN: a instance of location
    Location(string latitute, string longitude) : latitude(latitute), longitude(longitude) {};

    void print() {
        cout << "--- Location ---" << endl;
        cout << "Latitude: " << latitude;
        cout << "Longitude: " << longitude;
        cout << endl;
    }
};

#endif //LABSPACETEMPLATE_LOCATION_HPP
