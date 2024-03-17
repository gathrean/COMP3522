//
// Created by jyim3 on 2023-08-16.
//

#ifndef LABSPACETEMPLATE_CITY_INFO_QUEUE_HPP
#define LABSPACETEMPLATE_CITY_INFO_QUEUE_HPP

using namespace std;

#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <vector>
#include "city_info.hpp"

/*
 * CityInfoQueue is a shared resource between Producers and Consumers. It contains a vector
 * of CityInfo (dataQueue)
 * It contains methods to
 *  - manage adding, removing, and checking on dataQueue
 *      - dataQueue must be protected by locks since Producers and Consumers access it
 *  - manage whether new data is still being added by producers
 *
 */
class CityInfoQueue {
public:
    CityInfoQueue() { dataIncoming = true; }

    // add new data to dataQueue
    void put(const CityInfo cityInfo) {
        lock_guard<mutex> lock(accessQueueMutex);
        dataQueue.push_back(cityInfo);
        cout << "(+) Element has been ADDED to the queue. (Queue has " << dataQueue.size() << " elements)." << endl << endl;
    }

    // get and remove element from dataQueue
    CityInfo get() {
        CityInfo cityInfo;
        lock_guard<mutex> lock(accessQueueMutex);
        if (!dataQueue.empty()) {
            cityInfo = dataQueue.front();
            dataQueue.erase(dataQueue.begin());
        }

        cout << "(-) Element has been REMOVED from the queue. (Queue has " << dataQueue.size() << " elements left)." << endl;
        return cityInfo;
    }

    size_t size() const {
        std::lock_guard<std::mutex> lock(accessQueueMutex);
        return dataQueue.size();
    }

    bool empty() const {
        std::lock_guard<std::mutex> lock(accessQueueMutex);
        return dataQueue.size() <= 0;
    }

    bool isDataIncoming() {
        return dataIncoming;
    }

    bool setDataIncoming(bool data) {
        return dataIncoming = data;
    }

private:
    vector<CityInfo> dataQueue; //shared vector of CityInfos
    mutable std::mutex accessQueueMutex; //used to protect dataQueue
    bool dataIncoming; //boolean flag indicating if producers have finished gathering data
};

#endif //LABSPACETEMPLATE_CITY_INFO_QUEUE_HPP
