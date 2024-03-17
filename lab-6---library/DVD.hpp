//
// Created by Gathrean Dela Cruz on 2023-10-17.
//

#include "LibraryItem.hpp"

#pragma once

/*
 * Represents a single DVD in a library which is identified through
 * its call number.
 */
class DVD : public LibraryItem {

private:
    /*
     * Represents the DVD item's release date.
     */
    string release_date;

    /*
     * Represents the DVD item's region code.
     */
    int region_code;

public:
    /*
     * DVD Constructor
     * PRE: call_num, title, release_date are valid strings
     *      num_copies, region_code are valid integers
     * POST: Creates a DVD object with the given parameters
     * RETURN: DVD object
     */
    DVD(string call_num, string title, int num_copies, string release_date, int region_code)
            : LibraryItem(call_num, title, num_copies), release_date(release_date), region_code(region_code) {}

    /*
     * Getter for the number of copies of the DVD.
     * PRE: None
     * POST: None
     * RETURN: The number of copies of the DVD
     */
    inline int get_num_copies() const override { return num_copies; }

    /*
     * Getter for the title of the DVD.
     * PRE: None
     * POST: None
     * RETURN: The title of the DVD
     */
    inline string get_title() const override { return title; }

    /*
     * Getter for the call number of the DVD.
     * PRE: None
     * POST: None
     * RETURN: The call number of the DVD
     */
    inline string get_call_number() const override { return call_num; }

    /*
     * Getter for the release date of the DVD.
     * PRE: None
     * POST: None
     * RETURN: The release date of the DVD
     */
    inline string get_release_date() const { return release_date; }

    /*
     * Getter for the region code of the DVD.
     * PRE: None
     * POST: None
     * RETURN: The region code of the DVD
     */
    inline int get_region_code() const { return region_code; }

    /*
     * Overloaded Insertion Operator.
     * PRE: None
     * POST: Prints out the DVD item's information when user selects "Display all items" in the menu.
     * RETURN: The output stream
     */
    friend ostream& operator<<(ostream& os, const DVD& dvd) {
        dvd.display(os);
        return os;
    }

    /*
     * Displays the DVD item's information.
     * PRE: None
     * POST: Prints out the DVD item's information when user selects "Display all items" in the menu.
     * RETURN: None
     */
    inline void display(ostream& os) const override {
        os << "---- DVD: " << title << " ----" << endl
           << "Call Number: " << call_num << endl
           << "Number of Copies: " << num_copies << endl
           << "Release Date: " << release_date << endl
           << "Region Code: " << region_code << endl;
    }

    /*
     * DVD Destructor
     * PRE: None
     * POST: None
     * RETURN: None
     */
    ~DVD() = default;
};