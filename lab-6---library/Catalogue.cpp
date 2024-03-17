//
// Created by Gathrean Dela Cruz on 2023-10-16.
//

#include "Catalogue.hpp"

LibraryItem* Catalogue::retrieve_item_by_call_number(string call_number) {
    LibraryItem* found_item = nullptr;
    for (LibraryItem* library_item: item_list) {
        if (library_item->get_call_number() == call_number) {
            found_item = library_item;
            break;
        }
    }
    return found_item;
}

vector<LibraryItem*> Catalogue::find_items(string title) {
    vector<LibraryItem*> title_list;
    for (LibraryItem* library_item: item_list) {
        if (title == library_item->get_title()) {
            title_list.push_back(library_item);
        }
    }
    return title_list;
}

void Catalogue::add_item() {
    LibraryItemGenerator library_item_generator;
    string user_choice = library_item_generator.displayChoices();
    LibraryItem* new_item = library_item_generator.chooseItem(user_choice);

    bool found_item = retrieve_item_by_call_number(new_item->get_call_number());

    if (found_item) {
        cout << "Could not add item with call number " << new_item->get_call_number()
             << ". It already exists. ";
    } else {
        item_list.push_back(new_item);
        cout << endl << "Item added successfully! Item details:" << endl;
        cout << *new_item;
    }
}

void Catalogue::remove_item(string call_number) {
    LibraryItem* found_item = retrieve_item_by_call_number(call_number);
    if (found_item != nullptr) {
        cout << "Successfully removed " << found_item->get_title() <<
             " with call number: " << found_item->get_call_number() << endl;

        for (size_t i = 0; i < item_list.size(); i++) {
            if (item_list[i] == found_item) {
                item_list.erase(item_list.begin() + i);
                break;
            }
        }
        delete found_item;
    } else {
        cout << "Item with call number: " << call_number << " not found." << endl;
    }
}

void Catalogue::display_available_items() {
    cout << "\nItems List" << endl;
    cout << "--------------" << endl << endl;

    for (LibraryItem* library_item: item_list) {
        cout << *library_item << endl;
    }
}

bool Catalogue::reduce_item_count(string call_number) {
    LibraryItem* library_item = retrieve_item_by_call_number(call_number);
    if (library_item != nullptr) {
        library_item->decrement_number_of_copies();
        return true;
    }
    return false;
}

bool Catalogue::increment_item_count(string call_number) {
    LibraryItem* library_item = retrieve_item_by_call_number(call_number);
    if (library_item != nullptr) {
        library_item->increment_number_of_copies();
        return true;
    }
    return false;
}