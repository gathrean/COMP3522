//
// Created by jyim3 on 2023-08-16.
//

#ifndef LABSPACETEMPLATE_CONSUMER_HPP
#define LABSPACETEMPLATE_CONSUMER_HPP

using namespace std;

#include <iostream>
#include <chrono>
#include <thread>
#include "city_info_queue.hpp"

/*
 * Retrieves data from a shared CityInfoQueue
 */
class Consumer {
public:
    Consumer(CityInfoQueue &q) : queue(q), id(increment_id()) {}

    /*
     * Code in this overloaded operator will be executed by threads
     */
    void operator()() {
        /*
         * TODO add code
         * Consumers stays in a loop while more data is incoming or the queue is not empty
         *  Gets CityInfo from CityInfoQueue if the queue is not empty
         *  - prints the retrieved CityInfo, then sleeps for some time
         *  Consumers sleeps for some time if the queue is empty
         */
        while (queue.isDataIncoming() || !queue.empty()) {

            if (!queue.empty()) {
                cout << "    !!!" << endl << "(!) Consumer " << id << " is CONSUMING from the queue." << endl << endl;
                CityInfo cityInfo = queue.get();
                cityInfo.print();
                this_thread::sleep_for(chrono::milliseconds(500));
            } else {
                cout << "    Zzz..." << endl << "(!) Consumer " << id << " is SLEEPING since queue is empty." << endl << endl;
                this_thread::sleep_for(chrono::milliseconds(750));
            }
        }
    }

private:
    static int staticId;

    static int increment_id() {
        return ++staticId;
    }

    CityInfoQueue &queue;
    int id;
};

int Consumer::staticId = 0;
#endif //LABSPACETEMPLATE_CONSUMER_HPP
