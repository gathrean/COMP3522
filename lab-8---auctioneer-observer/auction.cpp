//
// Created by jyim3 on 2022-10-19.
//

#include "auction.hpp"

Auction::Auction(const vector<Bidder *> & bidders) : auctioneer() {
    for (Bidder * bidder: bidders) {
        // Register each bidder to the auctioneer
        auctioneer.register_bidder(bidder);
    }
}

void Auction::simulate_auction(const string & item, double start_price) {
    cout << "Auctioning " << item << " at starting price $" << start_price << endl;

    // The auctioneer starts the auction at the starting price
    auctioneer.accept_bid(start_price);

    // There are no participants
    if (auctioneer.get_highest_bidder() == nullptr) {
        cout << "No participants." << endl;
    } else {
        // The auctioneer announces the winner and the winning bid
        cout << "\nThe " << item << " goes to "
             << auctioneer.get_highest_bidder()->get_name() << " for $" << auctioneer.get_highest_bid() << endl;

        // The auctioneer announces the highest bid for each bidder
        cout << endl;
        for (Bidder * bidder: auctioneer.get_bidders()) {
            cout << "Bidder: " << bidder->get_name()
                 << ", Highest bid: $" << bidder->get_highest_bid()
                 << endl;
        }
    }
}