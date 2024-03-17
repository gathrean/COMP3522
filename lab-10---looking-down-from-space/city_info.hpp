//
// Created by jyim3 on 2023-08-16.
//

#ifndef LABSPACETEMPLATE_CITY_INFO_HPP
#define LABSPACETEMPLATE_CITY_INFO_HPP
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

/*
 * Expanded information representing information about a city
 * No need to add code, but you may if needed
 */
class CityInfo {
public:
    string latitude;
    string longitude;
    string timezoneId;
    int offset;
    string countryCode;
    string mapUrl;

    CityInfo() {}

    CityInfo(string latitude, string longitude, string timezoneId, int offset, string countryCode, string mapUrl) :
            latitude(latitude),
            longitude(longitude),
            timezoneId(timezoneId),
            offset(offset),
            countryCode(countryCode),
            mapUrl(mapUrl)
    {}

    void print() {
        cout << endl;
        cout << "--- CityInfo ---" << endl;
        cout << "- Latitude: " << latitude << endl;
        cout << "- Longitude: " << longitude << endl;
        cout << "- Time Zone ID: " << timezoneId << endl;
        cout << "- Offset: " << offset << endl;
        cout << "- Country Code: " << countryCode << endl;
        cout << "- Map URL: " << mapUrl << endl;
        cout << "----------------" << endl;
        cout << endl;
    }
};

#endif //LABSPACETEMPLATE_CITY_INFO_HPP
