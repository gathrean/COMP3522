//
// Created by Gathrean Dela Cruz on 2023-10-17.
//

#include <iostream>

#pragma once

using namespace std;

/*
 * Represents a single item in a library, which is identified through
 * its call number.
 */
class LibraryItem {

protected:
    /*
     * Represents the Library Item's call number.
     */
    string call_num;

    /*
     * Represents the Library Item's title.
     */
    string title;

    /*
     * Represents the Library Item's number of copies.
     */
    int num_copies;

public:

    /*
     * LibraryItem Constructor
     * PRE: call_num, title are valid strings
     *      num_copies is a valid integer
     *      author is a valid string
     * POST: Creates a LibraryItem object with the given parameters
     * RETURN: LibraryItem object
     */
    LibraryItem(string call_num, string title, int num_copies)
            : call_num(call_num), title(title), num_copies(num_copies) {}

    /*
     * Getter for the title of the Library Item
     * PRE: None
     * POST: None
     * RETURN: The title of the Library Item
     */
    virtual string get_title() const { return title; }

    /*
     * Getter for the call number of the Library Item
     * PRE: None
     * POST: None
     * RETURN: The call number of the Library Item
     */
    virtual string get_call_number() const { return call_num; }

    /*
     * Getter for the number of copies of the Library Item
     * PRE: None
     * POST: None
     * RETURN: The number of copies of the Library Item
     */
    virtual int get_num_copies() const { return num_copies; }

    /*
     * Increments the number of copies of a Library Item.
     * PRE: num_copies is a valid integer
     * POST: The number of copies of the Library Item is incremented by 1
     * RETURN: None
     */
    void increment_number_of_copies() { num_copies += 1; }

    /*
     * Decrements the number of copies of a Library Item.
     * PRE: num_copies is a valid integer.
     * POST: The number of copies of the Library Item is decremented by 1.
     * RETURN: None.
     */
    void decrement_number_of_copies() { num_copies -= 1; }

    /*
     * Checks if the Library Item is available.
     * PRE: None
     * POST: None
     * RETURN: True if the Library Item is available, false otherwise
     */
    virtual bool check_availability() const { return num_copies > 0; };

    /*
     * Overloaded Insertion Operator.
     * PRE: None
     * POST: Prints out the Library Item's information when user selects "Display all items" in the menu.
     * RETURN: The output stream
     */
    friend ostream& operator<<(ostream& os, const LibraryItem& libraryItem) {
        libraryItem.display(os);
        return os;
    }

    /*
     * Displays the Library Item's information.
     * PRE: None
     * POST: Prints out the Library Item's information when user selects "Display all items" in the menu.
     * RETURN: None
     */
    inline virtual void display(ostream& os) const {
        os << "---- Library Item: " << get_title() << " ----" << endl
           << "Call Number: " << get_call_number() << endl
           << "Number of Copies: " << get_num_copies() << endl;
    }

    /*
     * Virtual Destructor
     */
    ~LibraryItem() = default;
};