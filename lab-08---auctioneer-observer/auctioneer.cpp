//
// Created by jyim3 on 2022-10-19.
//

#include "auctioneer.hpp"

void Auctioneer::register_bidder(Bidder * bidder) {
    // Add the bidder to the list of tracked bidders
    bidders.push_back(bidder);
}

void Auctioneer::reset_auctioneer() {
    // Remove all bidders and reset the highest bid
    bidders.clear();
    highest_bid = 0;
    highest_bidder = nullptr; // good practice
}

void Auctioneer::notify_bidders() {
    // Notify all bidders except the highest bidder
    for (Bidder * bidder: bidders) {
        if (bidder != highest_bidder)
            bidder->update(this);
    }
}

void Auctioneer::accept_bid(double bid, Bidder * bidder) {
    if (highest_bid == 0) { // If it's the first bid
        highest_bid = bid;
        highest_bidder = bidder;
        notify_bidders();
    } else if (bid > highest_bid) { // If the bid is higher than the highest bid
        if_first_bid = false;
        highest_bid = bid;
        highest_bidder = bidder;
        notify_bidders();
    }
}