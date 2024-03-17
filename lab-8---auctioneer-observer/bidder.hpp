//
// Created by jyim3 on 2022-10-19.
//

#pragma once

#include <iostream>
#include <random>

using namespace std;

class Auctioneer; //forward declaration

class Bidder {
    /**
     *  The name of the bidder
     */
    string name;

    /**
     * The amount of money that the bidder is willing to spend.
     * The bidder will not make a bid greater than this amount.
     */
    double budget;

    /**
     * This is a floating point value between 0 and 100.
     * This represents the percentage probability chance that
     * this bidder will retaliate to a bid with their own bid.
     */
    double bid_probability;

    /**
     * This is a number greater than 1 (i.e. A value of 1.4 translate to 140%).
     * This percentage is the value of the new bid that the bidder places.
     * For example, if the bidder has a bid_crease_perc value of 1.5 (that is, 150%) then
     * if this bidder were to place a bid, it would be 1.5 times the current highest bid on the item.
     */
    double bid_increase_perc;

    /**
     * The highest bid amount that was bid by this bidder.
     */
    double highest_bid;

public:
    /**
     * Default Constructor
     * PRE: None
     * POST: A Bidder object is created with the default values for the member variables
     *      name, budget, bid_probability, and bid_increase_perc
     * RETURNS: None
     */
    Bidder(string name, double budget, double bid_probability, double bid_increase_perc)
            : name(name), budget(budget), bid_probability(bid_probability), bid_increase_perc(bid_increase_perc) {}

    /**
     * Update Method
     * PRE: auctioneer is a pointer to an Auctioneer object
     * POST: The bidder has placed a bid with the auctioneer
     * RETURNS: None
     */
    void update(Auctioneer * auctioneer);

    /**
     * Destructor
     * PRE: None
     * POST: The Bidder object is destroyed
     * RETURNS: None
     */
    ~Bidder() = default;

    /**
     * Highest Bid Getter
     * PRE: None
     * POST: The value of the highest bid is returned
     * RETURNS: A double value representing the highest bid amount
     */
    inline double get_highest_bid() { return highest_bid; }

    /**
     * Bidder Name Getter
     * PRE: None
     * POST: The name of the bidder is returned
     * RETURNS: A string representing the name of the bidder
     */
    inline string get_name() { return name; }

    /**
     * Insertion Operator Overload
     * PRE: os is a reference to an ostream object
     *      bidder is a constant reference to a Bidder object
     * POST: The name of the bidder is sent to the output stream
     * RETURNS: A reference to the ostream object to allow for chaining of << operator calls
     */
    friend ostream & operator<<(ostream & os, const Bidder & bidder) {
        os << bidder.name;
        return os;
    }
};

