//
// Created by jyim3 on 2022-10-19.
//

#pragma once

#include <vector>
#include "bidder.hpp"

using namespace std;

/**
 * The auctioneer acts as the "subject". This class is responsible for
 * tracking the highest bid and notifying the bidders if it changes.
*/
class Auctioneer {
    /**
     * A vector of bidder pointers that the auctioneer can notify.
     */
    vector<Bidder *> bidders;

    /**
     * The value of the highest current bid.
     */
    double highest_bid = 0;

    /**
     * A pointer to the highest bidder.
     */
    Bidder * highest_bidder = nullptr;

    /**
     * A boolean to check if it's the first bid.
     */
    bool if_first_bid = true;

public:

    /**
     * Default Constructor
     * PRE: None
     * POST: An Auctioneer object is created with the default values for the member variables
     * RETURNS: None
     */
    Auctioneer() = default;

    /**
     * Bidder Registerer
     * PRE: bidder is a pointer to a Bidder object
     * POST: bidder is added to the list of bidders
     * RETURN: None
     */
    void register_bidder(Bidder * bidder);

    /**
     * Auctioneer Resetter
     * highest bid to 0.
     * PRE: None
     * POST: The auctioneer is reset
     * RETURN: None
     */
    void reset_auctioneer();

    /**
     * Bidder Notifier
     * PRE: None
     * POST: The bidders are notified of the highest bid
     * RETURN: None
     */
    void notify_bidders();

    /**
     * Bid Acceptor
     * PRE: bid is a double, bidder is a pointer to a Bidder object
     * POST: The highest bid is updated and the bidders are notified
     * RETURN: None
     */
    void accept_bid(double bid, Bidder * bidder = nullptr);

    /**
     * Bidders Getter
     * PRE: None
     * POST: The list of bidders is returned
     * RETURN: A vector of pointers to Bidder objects
     */
    inline vector<Bidder *> get_bidders() { return bidders; }

    /**
     * Highest Bidder Getter
     * PRE: None
     * POST: The highest bidder is returned
     * RETURN: A pointer to a Bidder object
     */
    inline Bidder * get_highest_bidder() { return highest_bidder; }

    /**
     * Highest Bid Getter
     * PRE: None
     * POST: The highest bid is returned
     * RETURN: A double value representing the highest bid amount
     */
    inline double get_highest_bid() { return highest_bid; }

    /**
     * First Bid Getter
     * PRE: None
     * POST: The boolean value of if it's the first bid is returned
     * RETURN: A boolean value; 'true' if it's the first bid, 'false' otherwise
     */
    inline bool get_if_first_bid() { return if_first_bid; }

};