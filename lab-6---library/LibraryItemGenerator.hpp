//
// Created by Gathrean Dela Cruz on 2023-10-20.
//

#pragma once

#include <sstream>
#include "LibraryItem.hpp"
#include "Book.hpp"
#include "DVD.hpp"
#include "Journal.hpp"

using namespace std;

class LibraryItemGenerator {

public:

    /* Library Item Display
     * PRE: None.
     * POST: User input is extracted into string_input
     * RETURN: Displays the three types of Library Items.
     */
    string displayChoices();

    /*
     * PRE: string_input A string that contains the user's choice of Library Item.
     * POST: User is given a form to fill up for the Library Item.
     * RETURN: Adds the user-generated Library Item to the Catalogue.
     */
    LibraryItem* chooseItem(string string_input);

};
