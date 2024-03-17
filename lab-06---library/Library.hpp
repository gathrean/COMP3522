//
// Created by jyim3 on 2022-10-19.
// Edited by Gathrean Dela Cruz on 2023-10-17.
//

#pragma once

#include <vector>
#include <sstream>
#include "Catalogue.hpp"
#include "LibraryItem.hpp"

using namespace std;

/*
 * A helper function to clean the cin buffer.
 */
inline void clean_cin() {
    // Clear out bad bits
    cin.clear();

    // Clear the garbage in buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/*
 * The Library class consists of a list of items and provides an
 * interface for users to check out, return, and find items.
 */
class Library {

private:

    // The list of items in the library
    vector<LibraryItem*> item_list;

    // The catalogue of items in the library
    Catalogue* catalogue;

public:

    /* Library Constructor
     * PRE: item_list is a vector of library item pointers.
     * POST: item_list is initialized to contain the given list of items.
     * RETURN: None.
     */
    inline Library(vector<LibraryItem*> item_list) { this->catalogue = new Catalogue(item_list); }

    /* Item Check Out
     * PRE: call_number is a string representing the call number of the item.
     * POST: The item with the given call number is checked out.
     * RETURN: An output message depending on the status of the checkout.
     */
    void check_out(string call_number);

    /* Item Returner
     * PRE: call_number is a string representing the call number of the item.
     * POST: The item with the given call number is returned.
     * RETURN: An output message depending on the status of the return.
     */
    void return_item(string call_number);

    /* Library Menu Display
     * PRE: None.
     * POST: The library menu is displayed.
     * RETURN: None.
     */
    void display_library_menu();

    /* Virtual Library Destructor
     * PRE: None.
     * POST: The library is deleted.
     * RETURN: None.
     */
    inline ~Library() { delete (catalogue); };

};
