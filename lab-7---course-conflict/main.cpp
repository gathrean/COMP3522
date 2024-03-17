//Name: Gathrean Dela Cruz
//Student# : A01167248

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>

#include "Course.hpp"

using namespace std;

/*
 * read courses - reads course data from a file
 * @param - fileName - the name of the file to read from
 */
vector<Course> readCourses(const string& fileName) {
    vector<Course> courses;
    ifstream inputFile(fileName);

    // if file was opened successfully, read in data
    if (inputFile.is_open()) {
        string courseTitle;
        string dayOfWeek;
        unsigned int startTime, endTime;

        // Read in course data from file
        while (inputFile >> courseTitle >> dayOfWeek >> startTime >> endTime) {
            Course::dayOfWeek day;
            if (dayOfWeek == "M") {
                day = Course::MON;
            } else if (dayOfWeek == "T") {
                day = Course::TUE;
            } else if (dayOfWeek == "W") {
                day = Course::WED;
            } else if (dayOfWeek == "R") {
                day = Course::THUR;
            } else if (dayOfWeek == "F") {
                day = Course::FRI;
            } else {
                cerr << "Invalid day abbreviation: " << dayOfWeek << endl;
                continue;
            }

            // Create a new course and add it to the vector
            Course newCourse(courseTitle, day, startTime, endTime);
            courses.push_back(newCourse);
        }

        inputFile.close();
    } else {
        cerr << "Unable to open file: " << fileName << endl;
    }

    return courses;
}

/*
 * print schedule - outputs course schedule to the screen
 * @param - courses - the list of courses to print
 */
void printSchedule(const vector<Course>& courses) {
    // DONE: implement your print using the copy algorithm, 2 iterators, and an ostream_iterator
    copy(courses.begin(), courses.end(), ostream_iterator<Course>(cout, "\n"));
}

/*
 * find conflicts - finds and prints all schedule conflicts
 * @param - courses - the list of courses to check for conflicts
 */
void findConflicts(const vector<Course>& courses) {
    vector<pair<Course, Course>> conflicts;

    // Find and print conflicts
    for (auto it1 = courses.begin(); it1 != prev(courses.end()); ++it1) {
        for (auto it2 = next(it1); it2 != courses.end(); ++it2) {
            if (*it1 == *it2) {
                cout << "CONFLICT:" << endl;
                cout << *it1 << endl;
                cout << *it2 << endl << endl;
            }
        }
    }
}

/*
 * main function - entry point for the program
 */
int main() {
    // DONE: read from courses.txt
    // DONE: store data in an STL container
    vector<Course> courses = readCourses("../courses.txt");

    // DONE: sort your STL container with the sort algorithm
    sort(courses.begin(), courses.end());

    // DONE: implement code to determine schedule conflicts
    // DONE: print out schedule conflicts
    findConflicts(courses);

    // DONE: print out schedule
    printSchedule(courses);
    return 0;
}
