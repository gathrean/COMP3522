//
// Created by Gathrean Dela Cruz on 2023-09-25.
//

#include "animal.hpp"
#include <random>

const int INT_ZERO = 0;
const double DBL_ZERO = 0.0;

/**
 * Default constructor with only two coordinates
 */
Animal::Animal() {
    age = INT_ZERO;
    isAlive = true;
    coordinate.x = DBL_ZERO;
    coordinate.y = DBL_ZERO;
    uniqueID = generateRandomId();
    std::cout << "Constructing an Animal object [ID: " << uniqueID << "]" << std::endl;
}

/**
 * Constructor but with two coordinates
 */
Animal::Animal(int age, double x, double y) {
    age = INT_ZERO;
    coordinate.x = x;
    coordinate.y = y;
    uniqueID = generateRandomId();
    std::cout << "Constructing an Animal object [ID: " << uniqueID << "], with two coordinates" << std::endl;
}

/**
 * Constructor but with three coordinates
 */
Animal::Animal(int age, double x, double y, double z) {
    age = INT_ZERO;
    coordinate.x = x;
    coordinate.y = y;
    coordinate.z = z;
    uniqueID = generateRandomId();
    std::cout << "Constructing an Animal object [ID: " << uniqueID << "], with three coordinates" << std::endl;
}

/**
 * Copy constructor
 */
Animal::Animal(const Animal &animal) {
    age = animal.age;
    isAlive = animal.isAlive;
    coordinate.x = animal.coordinate.x;
    coordinate.y = animal.coordinate.y;
    coordinate.z = animal.coordinate.z;
    uniqueID = generateRandomId();
    std::cout << "Constructing an Animal object [ID: " << uniqueID << "], with copy constructor" << std::endl;
}

/**
 * Move method using two coordinates
 * @param x
 * @param y
 */
void Animal::move(double x, double y) {
    coordinate.x += x;
    coordinate.y += y;
    std::cout << "Animal [ID: " << uniqueID << "] moved to (" << coordinate.x << ", " << coordinate.y << ")" << std::endl;
}

/**
 * Move method using three coordinates
 * @param x
 * @param y
 * @param z
 */
void Animal::move(double x, double y, double z) {
    coordinate.x += x;
    coordinate.y += y;
    coordinate.z += z;
    std::cout << "Animal [ID: " << uniqueID << "] moved to (" << coordinate.x << ", " << coordinate.y << ", " << coordinate.z
              << ")" << std::endl;
}

/**
 * Virtual Destructor
 * @param uniqueID
 */
Animal::~Animal() {
    std::cout << "Destructing an Animal object [ID: " << uniqueID << "]" << std::endl;
}

/**
 * Animal's sleep function
 * @param uniqueID
 * @param isAlive
 */
void Animal::sleep() const {
    if (isAlive) {
        std::cout << "Animal [ID: " << uniqueID << "] is sleeping." << std::endl;
    } else {
        std::cout << "Animal [ID: " << uniqueID << "] is dead." << std::endl;
    }
}

/**
 * Animal's eat function
 * @param uniqueID
 * @param isAlive
 */
void Animal::eat() const {
    if (isAlive) {
        std::cout << "Animal [ID: " << uniqueID << "] is eating." << std::endl;
        return;
    } else {
        std::cout << "Animal [ID: " << uniqueID << "] is dead." << std::endl;
    }
}

/**
 * setAlive member function
 * @param alive
 */
void Animal::setAlive(bool alive) {
    isAlive = alive;
}

bool Animal::getAlive() {
    return isAlive;
}

// Getters for coordinates
double Animal::getX() const {
    return coordinate.x;
}

double Animal::getY() const {
    return coordinate.y;
}

double Animal::getZ() const {
    return coordinate.z;
}

long Animal::getID() const {
    return uniqueID;
}

/**
 * Overload the insertion operator (<<)
 * @param os
 * @param animal
 * @return
 */
std::ostream &operator<<(std::ostream &os, const Animal &animal) {
    os << "Animal: [age=" << animal.age << ", id=" << animal.uniqueID << ", alive=" << animal.isAlive
       << ", location(" << animal.coordinate.x << ", " << animal.coordinate.y
       << ", " << animal.coordinate.z << ")]";
    return os;
}

/**
 * Helper function to generate random IDs
 * @return random 3-digit ID
 */
long Animal::generateRandomId() {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<long> distribution(10, 99);
    return distribution(generator);
}