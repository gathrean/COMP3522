//
// Created by jyim3 on 2022-10-19.
//

#pragma once

#include "bidder.hpp"
#include "auctioneer.hpp"
#include <vector>
#include <string>

class Bidder; // Forward declaration

/**
 * Simulates an auction. Is responsible for driving the auctioneer and
 * the bidders.
 */
class Auction {

private:

    Auctioneer auctioneer;

public:

    /**
     * Default Constructor
     * PRE: bidders is a vector of Bidder pointers
     * POST: Auctioneer is initialized with the bidders
     * RETURN: None
     */
    explicit Auction(const vector <Bidder *>& bidders);

    /**
     * Auction Simulator
     * PRE: item is a string, start_price is a double
     * POST: Auctioneer is initialized with the bidders
     * RETURN: None
     */
    void simulate_auction(const string& item, double start_price);
};
