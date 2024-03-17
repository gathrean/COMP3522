#include "Course.hpp"

using namespace std;

Course::Course(string title, dayOfWeek day, unsigned int start_time, unsigned int finish_time)
        : title(title), day(day), start_time(start_time), finish_time(finish_time) {
}

Course::Course(const Course& m)
        : title(m.title), day(m.day), start_time(m.start_time), finish_time(m.finish_time) {
}

Course& Course::operator=(Course m) {
    title = m.title;
    day = m.day;
    start_time = m.start_time;
    finish_time = m.finish_time;
    return *this;
}

bool Course::operator==(const Course& m) const {
    if (day != m.day) {
        // False if they're not on the same day
        return false;
    } else if (finish_time <= m.start_time || start_time >= m.finish_time) {
        // False if they're on the same day, but don't overlap
        return false;
    } else {
        // True if they're on the same day, and overlap
        return true;
    }
}

bool Course::operator<(const Course& m) const {
    if (this->day != m.day) {
        // Return true if this course is on an earlier day
        return this->day < m.day;
    } else if (this->start_time != m.start_time) {
        // Return true if this course starts earlier on the same day
        return this->start_time < m.start_time;
    } else {
        // Return true if this course finishes earlier on the same day
        return this->finish_time < m.finish_time;
    }
}

ostream& operator<<(ostream& os, const Course& m) {
    string day;
    if (m.day == 0) {
        day = "M";
    } else if (m.day == 1) {
        day = "T";
    } else if (m.day == 2) {
        day = "W";
    } else if (m.day == 3) {
        day = "R";
    } else if (m.day == 4) {
        day = "F";
    } else {
        cerr << "Invalid day abbreviation" << endl;
    }

    os << m.title << " " << day << " " << m.start_time << " " << m.finish_time;

    return os;
}