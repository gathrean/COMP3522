//
// Created by jyim3 on 2022-10-19.
//

#pragma once

#include <iostream>
#include "LibraryItem.hpp"

using namespace std;

/*
 * Represents a single book in a library which is identified through
 * its call number.
*/
class Book : public LibraryItem {

private:

    // Represents the Book item's author.
    string author;

public:

    /*
     * Book Constructor
     * PRE: call_num, title, author are valid strings
     * POST: Creates a book object with the given parameters
     * RETURN: Book object
     */
    Book(string call_num, string title, int num_copies, string author)
            : LibraryItem(call_num, title, num_copies), author(author) {}

    /*
     * Getter for the number of copies of the book
     * PRE: None
     * POST: None
     * RETURN: The number of copies of the book
     */
    inline int get_num_copies() const override { return num_copies; }

    /*
     * Getter for the title of the book
     * PRE: None
     * POST: None
     * RETURN: The title of the book
     */
    inline string get_title() const override { return title; }

    /*
     * Getter for the call number of the book
     * PRE: None
     * POST: None
     * RETURN: The call number of the book
     */
    inline string get_call_number() const override { return call_num; }

    /*
     * Getter for the author of the book
     * PRE: None
     * POST: None
     * RETURN: The author of the book
     */
    inline string get_author() const { return author; }

    /*
     * Overloaded Insertion Operator.
     * PRE: None
     * POST: Prints out the book's information when user selects "Display all items" in the menu.
     * RETURN: The output stream
     */
    friend ostream& operator<<(ostream& os, const Book& book) {
        book.display(os);
        return os;
    }


    /*
     * Helper function for the overloaded insertion operator.
     * PRE: None
     * POST: Prints out the book's information when user selects "Display all items" in the menu.
     * RETURN: None
     */
    inline void display(ostream& os) const override {
        os << "---- Book: " << title << " ----" << endl
           << "Call Number: " << call_num << endl
           << "Number of Copies: " << num_copies << endl
           << "Author: " << author << endl;
    }

    /*
     * Book Destructor
     * PRE: None
     * POST: None
     * RETURN: None
     */
    ~Book() = default;
};