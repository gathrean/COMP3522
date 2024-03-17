//
// Created by jyim3 on 2022-10-19.
//

#include "bidder.hpp"
#include "auctioneer.hpp"

void Bidder::update(Auctioneer * auctioneer) {

    // Generate a random number between 0 and 100
    double random_number = (double) rand() / RAND_MAX * 100;

    // Get the highest bid and highest bidder
    double auction_high_bid = auctioneer->get_highest_bid();
    double bid_increase = auctioneer->get_highest_bid() * bid_increase_perc;
    Bidder * highest_bidder = auctioneer->get_highest_bidder();

    // If the bidder is not the highest bidder
    if (auctioneer->get_highest_bidder() != this) {

        // If the bidder has enough budget to bid
        if (bid_increase <= budget) {

            // If the bidder decides to bid
            if (random_number <= bid_probability) {

                // If the bidder is the first bidder
                if (auctioneer->get_if_first_bid()) {
                    cout << name << " bidded $"
                         << bid_increase << " in response to the Starting bid of $"
                         << auction_high_bid << endl;

                    // Update the highest bid and bidder
                    highest_bid = bid_increase;
                    auctioneer->accept_bid(bid_increase, this);
                } else { // If the bidder is not the first bidder
                    cout << name << " bidded $"
                         << bid_increase << " in response to "
                         << *highest_bidder << "'s bid of $"
                         << (int)auction_high_bid << endl;

                    // Update the highest bid and bidder
                    highest_bid = bid_increase;
                    auctioneer->accept_bid(bid_increase, this);
                }
            }
        }
    }
}