//
// Created by Gathrean Dela Cruz on 2023-10-20.
//

#include "LibraryItemGenerator.hpp"

void clean_cin() {
    //clearing out bad bits
    cin.clear();

    //clearing garbage in buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

string LibraryItemGenerator::displayChoices() {
    cout << endl << "Choose library item type:" << endl;
    cout << "-----------------------" << endl;
    cout << "1. Book" << endl
         << "2. DVD" << endl
         << "3. Journal" << endl;
    cout << "-----------------------" << endl;
    cout << "Please enter your choice (1-3)" << endl;
    string string_input;
    cin >> string_input;
    return string_input;
}

LibraryItem* LibraryItemGenerator::chooseItem(std::string string_input) {

    int user_input = -1;

    stringstream ss{string_input};

    // (From Library.hpp)
    // cleans any bad bits before reading input
    clean_cin();

    // ss will look for an integer in the string
    // and if it finds one, it will store it in user_input
    if (ss >> user_input) {
        if (user_input == 1) { // 1. Book
            cout << "Enter Book Call Number: " << endl;
            string user_book_call_num;
            cin >> user_book_call_num;

            clean_cin();

            cout << "Enter Book Title: " << endl;
            string user_book_title;
            getline(cin, user_book_title);

            clean_cin();

            cout << "Enter Book Number of Copies: " << endl;
            int user_book_num_copies;
            cin >> user_book_num_copies;

            clean_cin();

            cout << "Enter Book Author: " << endl;
            string user_book_author;
            getline(cin, user_book_author);

            clean_cin();

            LibraryItem* user_book = new Book(user_book_call_num, user_book_title, user_book_num_copies,
                                              user_book_author);

            return user_book;

        } else if (user_input == 2) { // 2. DVD
            cout << "Enter DVD Call Number: " << endl;
            string user_dvd_call_num;
            cin >> user_dvd_call_num;

            clean_cin();

            cout << "Enter DVD Title: " << endl;
            string user_dvd_title;
            getline(cin, user_dvd_title);

            clean_cin();

            cout << "Enter DVD Number of Copies: " << endl;
            int user_dvd_num_copies;
            cin >> user_dvd_num_copies;

            clean_cin();

            cout << "Enter DVD Release Date: " << endl;
            string user_dvd_release_date;
            getline(cin, user_dvd_release_date);

            clean_cin();

            cout << "Enter DVD Region Code: " << endl;
            int user_dvd_region_code;
            cin >> user_dvd_region_code;

            clean_cin();

            LibraryItem* user_dvd = new DVD(user_dvd_call_num, user_dvd_title, user_dvd_num_copies,
                                            user_dvd_release_date, user_dvd_region_code);

            return user_dvd;

        } else if (user_input == 2 + 1) { // 3. Journal
            cout << "Enter Journal Call Number: " << endl;
            string user_journal_call_num;
            cin >> user_journal_call_num;

            clean_cin();

            cout << "Enter Journal Title: " << endl;
            string user_journal_title;
            getline(cin, user_journal_title);

            clean_cin();

            cout << "Enter Journal Number of Copies: " << endl;
            int user_journal_num_copies;
            cin >> user_journal_num_copies;

            clean_cin();

            cout << "Enter Journal Author: " << endl;
            string user_journal_author;
            getline(cin, user_journal_author);

            clean_cin();

            cout << "Enter Journal Issue Number: " << endl;
            int user_journal_issue_number;
            cin >> user_journal_issue_number;

            clean_cin();

            cout << "Enter Journal Publisher: " << endl;
            string user_journal_publisher;
            getline(cin, user_journal_publisher);

            clean_cin();

            LibraryItem* user_journal = new Journal(user_journal_call_num, user_journal_title, user_journal_num_copies,
                                                    user_journal_author, user_journal_issue_number,
                                                    user_journal_publisher);

            return user_journal;
        } else {
            cout << "Could not process the input. Please enter a"
                    " number from 1 - 3." << endl;

            cout << "Thank you for visiting the Library." << endl;
        }
    }
}