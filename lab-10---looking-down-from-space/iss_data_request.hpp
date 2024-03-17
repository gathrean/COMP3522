//
// Created by jyim3 on 2023-08-16.
//

#ifndef LABSPACETEMPLATE_ISS_DATA_REQUEST_HPP
#define LABSPACETEMPLATE_ISS_DATA_REQUEST_HPP

using namespace std;
#include <iostream>
#include <chrono>
#include <vector>
#include "location.hpp"
#include "city_info.hpp"

/*
 * ---DO NOT TOUCH THIS FILE---
 * Class to simulate making a web request to get city information given a Location object
 */
class ISSDataRequest {
private:
    // Private constructor to prevent direct instantiation
    ISSDataRequest() {
        allCityInfo = initAllCityInfo();
    }

    // Private copy constructor and assignment operator to prevent cloning
    ISSDataRequest(const ISSDataRequest&) = delete;
    ISSDataRequest& operator=(const ISSDataRequest&) = delete;

    vector<CityInfo> allCityInfo;

    //read file and extract city information
    //return: vector of CityInfo
    vector<CityInfo> initAllCityInfo() {
        const int LAT_INDEX = 0;
        const int LONG_INDEX = 1;
        const int TIME_ZONE_INDEX = 2;
        const int OFFSET_INDEX = 3;
        const int COUNTRY_CODE_INDEX = 4;
        const int MAP_INDEX = 5;
        string PATH = "../all_city_info.txt";

        std::vector<CityInfo> cityInfoList;
        std::ifstream inputFile(PATH);

        if (!inputFile.is_open()) {
            std::cerr << "Unable to open file." << std::endl;
            exit(-1);
        }

        CityInfo cityInfo;
        std::string line;

        while (std::getline(inputFile, line)) {

            if (line.empty()) {
                continue;
            }

            std::istringstream iss(line);
            std::string temp;
            std::vector<std::string> tokens;

            while (std::getline(iss, temp, '\t')) {
                tokens.push_back(temp);
            }

            cityInfo.latitude = to_string((std::stod(tokens[LAT_INDEX])));
            cityInfo.longitude = to_string(std::stod(tokens[LONG_INDEX]));
            cityInfo.timezoneId = tokens[TIME_ZONE_INDEX];
            cityInfo.offset = std::stod(tokens[OFFSET_INDEX]);
            cityInfo.countryCode = tokens[COUNTRY_CODE_INDEX];
            cityInfo.mapUrl = tokens[MAP_INDEX];

            cityInfoList.push_back(cityInfo);
        }
        inputFile.close();
        return cityInfoList;
    }

public:
    // Static method to access the single instance
    static ISSDataRequest& getInstance() {
        static ISSDataRequest instance; // Guaranteed to be created only once
        return instance;
    }

    CityInfo get_city_info(const Location& city) {
        int WAIT_TIME = 100;
        std::this_thread::sleep_for(std::chrono::milliseconds(WAIT_TIME)); //simulate time to retrieve data
        // checks latitude and longitude match CityInfo in queue
        for (CityInfo c : allCityInfo) {
            if(c.latitude == city.latitude && c.longitude == city.longitude) {
                return c;
            }
        }
        cerr << "No city with that latitude and longitude" << endl;
        return CityInfo("latitude", "longitude", "timezoneId", -1, "countryCode", "mapUrl"); // Placeholder return
    }
};

#endif //LABSPACETEMPLATE_ISS_DATA_REQUEST_HPP
