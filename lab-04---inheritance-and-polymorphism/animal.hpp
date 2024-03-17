//
// Created by Gathrean Dela Cruz on 2023-09-25.
//

#ifndef LAB4TEMPLATE_ANIMAL_HPP
#define LAB4TEMPLATE_ANIMAL_HPP

#include <utility>
#include <iostream>

typedef struct Coordinate {
    double x;
    double y;
    double z;
} Coordinate;

class Animal {

protected:
    int age;
    long uniqueID;
//    static long ID_MAKER;
    bool isAlive;
    Coordinate coordinate;

public:
    // Default Constructor
    Animal();

    // Constructor with two coordinates
    Animal(int age, double x, double y);

    // Constructor with three coordinates
    Animal(int age, double x, double y, double z);

    // Copy constructor
    Animal(const Animal &animal);

    // Virtual Destructor
    virtual ~Animal();

    virtual void move(double x, double y);

    virtual void move(double x, double y, double z);

    virtual void sleep() const;

    virtual void eat() const;

    // setAlive member function
    void setAlive(bool alive);

    // getAlive member function
    bool getAlive();

    long getID() const;

    double getX() const;

    double getY() const;

    double getZ() const;

    // Helper function to generate random IDs
    static long generateRandomId();

    // Overload the global insertion operator (<<)
    friend std::ostream &operator<<(std::ostream &os, const Animal &animal);
};

#endif //LAB4TEMPLATE_ANIMAL_HPP
