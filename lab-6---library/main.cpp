//Name: Dela Cruz, Gathrean
//Student#: A01167248

#include <iostream>
#include "Library.hpp"
#include "Catalogue.hpp"

/*
 * Generates a list of dummy library items.
 * PRE: None
 * POST: None
 * RETURN: A vector of LibraryItem pointers
 */
vector<LibraryItem*> generate_test_items() {
    vector<LibraryItem*> item_list;
    item_list.push_back(new Book("100.200.300", "Harry Potter 1", 252341, "J K Rowling"));
    item_list.push_back(new DVD("400.500.600", "The Cat in the Hat", 14393, "Nov 11, 1993", 37));
    item_list.push_back(new Journal("700.800.900", "Leonardo da Vinci Journal", 234223, "Leonardo da Vinci", 152,
                                    "Da Vinci Press"));
    return item_list;
}

/*
 * The Main function.
 */
int main() {
    vector<LibraryItem*> item_list = generate_test_items();
    Library my_epic_library(item_list);
    my_epic_library.display_library_menu();
    return 0;
}
