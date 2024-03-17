//
// Created by jyim3 on 2023-08-16.
//

#ifndef LABSPACETEMPLATE_PRODUCER_HPP
#define LABSPACETEMPLATE_PRODUCER_HPP

using namespace std;

#include <iostream>
#include <chrono>
#include <thread>
#include "iss_data_request.hpp"
#include "location.hpp"
#include "city_info_queue.hpp"


class Producer {
public:
    Producer(const std::vector<Location> locations, CityInfoQueue &queue)
            : locations(locations), queue(queue), id(increment_id()) {}

    /*
     * Code in this overloaded operator will be executed by threads
     */
    void operator()() {
        /*
         * TODO add code
         * Queries the ISSDataRequest Singleton with all Location data to retrieve CityInfo
         * -Adds CityInfo to the shared CityInfoQueue
         * Sleep for some time after a certain number of successful retrievals
         */
        for (const auto &location: locations) {
            CityInfo cityInfo = ISSDataRequest::getInstance().get_city_info(location);
            cout << "(+) Producer " << id << " is ADDING to the Queue" << endl;
            queue.put(cityInfo);

            if (queue.size() % 5 == 0) {
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        }
        queue.setDataIncoming(false);
    }

private:
    static int staticId;

    static int increment_id() {
        return ++staticId;
    }

    std::vector<Location> locations;
    CityInfoQueue &queue;
    int id;
};

int Producer::staticId = 0;
#endif //LABSPACETEMPLATE_PRODUCER_HPP
