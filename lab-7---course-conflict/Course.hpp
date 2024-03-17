// Course.h
#include <iostream>

using namespace std;

class Course {

public:
    // Enumerated type for the days with classes
    enum dayOfWeek {
        MON, TUE, WED, THUR, FRI
    };

    // Default Constructor
    Course(string title, dayOfWeek day, unsigned int start_time, unsigned int finish_time);

    // Copy Constructor
    Course(const Course& m);

    // Overloaded Assignment operator
    Course& operator=(Course m);

    // Overloaded Less Than operator
    bool operator<(const Course& m) const;

    // Overloaded Equality operator
    bool operator==(const Course& m) const;

    // Helper operator for output
    friend ostream& operator<<(ostream& os, const Course& m);

private:
    // Name of Course
    string title;

    // Day of Course
    dayOfWeek day;

    // Course start time in HHMM format
    unsigned int start_time;

    // Course finish time in HHMM format
    unsigned int finish_time;

};
