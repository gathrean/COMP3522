//
// Created by Gathrean Dela Cruz on 2023-10-16.
//

#pragma once

#include <vector>
#include <limits>
#include "Book.hpp"
#include "DVD.hpp"
#include "Journal.hpp"
#include "LibraryItemGenerator.hpp"

class Catalogue {

private:

    /*
     * A vector of Library Item pointers
     */
    vector<LibraryItem*> item_list;

public:

    /*
     * Constructs the catalogue with a list of library items.
     * PRE: item_list is a vector of Library Item pointers
     */
    Catalogue(vector<LibraryItem*> item_list) : item_list(item_list) {}

    /*
     * Item Retriever by Call Number
     * PRE: call_number is a string.
     * POST: call_number is unchanged, but
     * RETURN: The pointer to the requested item that matches the call number.
     */
    LibraryItem* retrieve_item_by_call_number(string call_number);

    /*
     * Item Finder by Title
     * PRE: title is a string.
     * POST: title is unchanged, but used as a reference to find item.
     * RETURN: The vector list of items that matches the title.
     */
    vector<LibraryItem*> find_items(string title);

    /*
     * Item Adder
     * PRE:
     * POST: LibraryItemGenerator object is created
     * POST: user_choice string is created
     * POST: A pointer to a LibraryItem is created
     * RETURN: A new library item is created with details enter by user.
     */
    void add_item();

    /*
     * Item Remover
     * PRE: call_number is a string representing the call number of the item.
     * POST: call_number is unchanged, but used to find the item with matching call number.
     * RETURN: The found item will be removed from the item_list.
     */
    void remove_item(string call_number);

    /*
     * Item Display
     * PRE: item_list if a vector of Library Item pointers
     * POST: item_list is unchanged.
     * RETURN: Displays the list of items in the console.
     */
    void display_available_items();

    /*
     * Item Count Reducer
     * PRE: call_number is a string representing the call number of the item.
     * POST: LibraryItem's decrement_number_of_copies() is a called if
     *       the item with same call number is found.
     * RETURN: True if the item was found and count is decremented, false otherwise.
     */
    bool reduce_item_count(string call_number);

    /*
     * PRE: call_number is a string representing the call number of the item.
     * POST: LibraryItem's increment_number_of_copies() is a called if
     *       the item with same call number is found.
     * RETURN: True if the item was found and count is incremented, false otherwise.
     */
    bool increment_item_count(string call_number);

    /*
     * Catalogue Virtual Destroyer
     * PRE: None
     * POST: Catalogue object is destroyed
     * RETURN: None
     */
    inline ~Catalogue() = default;
};

