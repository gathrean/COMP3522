//
// Created by Gathrean Dela Cruz on 2023-10-17.
//

#include "LibraryItem.hpp"

#pragma once

/*
 * Represents a single DVD in a library which is identified through
 * its call number.
 */
class Journal : public LibraryItem {

private:
    /*
     * Represents the Journal item's author.
     */
    string author;

    /*
     * Represents the Journal item's issue number.
     */
    int issue_number;

    /*
     * Represents the Journal item's publisher.
     */
    string publisher;

public:

    /*
     * Journal Constructor
     * PRE: call_num, title, author, publisher are valid strings
     *      num_copies, issue_number are valid integers
     *      release_date is a valid date
     *      region_code is a valid integer
     * POST: Creates a Journal object with the given parameters
     * RETURN: Journal object
     */
    Journal(string call_num, string title, int num_copies, string author, int issue_number, string publisher)
            : LibraryItem(call_num, title, num_copies), author(author), issue_number(issue_number),
              publisher(publisher) {}

    /*
     * Getter for the number of copies of the Journal.
     * PRE: None
     * POST: None
     * RETURN: The number of copies of the Journal
     */
    inline int get_num_copies() const override { return num_copies; }

    /*
     * Getter for the title of the Journal.
     * PRE: None
     * POST: None
     * RETURN: The title of the Journal
     */
    inline string get_title() const override { return title; }

    /*
     * Getter for the call number of the Journal.
     * PRE: None
     * POST: None
     * RETURN: The call number of the Journal
     */
    inline string get_call_number() const override { return call_num; }

    /*
     * Getter for the author of the Journal.
     * PRE: None
     * POST: None
     * RETURN: The author of the Journal
     */
    inline string get_author() const { return author; }

    /*
     * Getter for the issue number of the Journal.
     * PRE: None
     * POST: None
     * RETURN: The issue number of the Journal
     */
    inline int get_issue_number() const { return issue_number; }

    /*
     * Getter for the publisher of the Journal.
     * PRE: None
     * POST: None
     * RETURN: The publisher of the Journal
     */
    inline string get_publisher() const { return publisher; }

    /*
     * Overloaded Insertion Operator.
     * PRE: None
     * POST: Prints out the Journal's information when user selects "Display all items" in the menu.
     * RETURN: The output stream
     */
    friend ostream& operator<<(ostream& os, const Journal& journal) {
        journal.display(os);
        return os;
    }

    /*
     * Displays the Journal item's information.
     * PRE: None
     * POST: Prints out the Journal item's information when user selects "Display all items" in the menu.
     * RETURN: None
     */
    inline void display(ostream& os) const override {
        os << "---- Journal: " << title << " ----" << endl
           << "Call Number: " << call_num << endl
           << "Number of Copies: " << num_copies << endl
           << "Author: " << author << endl
           << "Issue Number: " << issue_number << endl
           << "Publisher: " << publisher << endl;
    }

    /*
     * Journal Destructor
     */
    ~Journal() = default;
};
