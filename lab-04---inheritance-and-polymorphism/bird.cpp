//
// Created by Gathrean Dela Cruz on 2023-09-25.
//
#include "bird.hpp"

const int INT_ZERO = 0;
const double DBL_ZERO = 0.0;

/**
 * Default constructor with only two coordinates
 * @param age
 * @param isAlive
 * @param x
 * @param y
 * @param z for flying
 * @param uniqueID
 */
Bird::Bird() : Animal() {
    age = INT_ZERO;
    isAlive = true;
    coordinate.x = DBL_ZERO;
    coordinate.y = DBL_ZERO;
    uniqueID = generateRandomId();
    std::cout << "Constructing a Bird object. [ID: " << this->uniqueID << "]" << std::endl;
}

/**
 * Constructor but with four parameters
 * @param age
 * @param x
 * @param y
 * @param z for flying
 * @param uniqueID
 */
Bird::Bird(int age, double x, double y, double z) {
    this->age = age;
    coordinate.x = x;
    coordinate.y = y;
    coordinate.z = z;
    uniqueID = generateRandomId();
    std::cout << "Constructing a Bird object [ID: " << this->uniqueID << "], with 4 parameters (age, x, y, z)" << std::endl;
}

/**
 * Copy constructor
 * @param bird
 */
Bird::Bird(const Bird &bird)  : Animal(bird) {
    age = bird.age;
    coordinate.x = bird.coordinate.x;
    coordinate.y = bird.coordinate.y;
    coordinate.z = bird.coordinate.z;
    std::cout << "Constructing a Bird object [ID: " << this->uniqueID << "] with copy constructor" << std::endl;
}

/**
 * Virtual Destructor
 * @param uniqueID
 */
Bird::~Bird() {
    std::cout << "Destructing a Bird object [ID: " << this->uniqueID << "]" << std::endl;
}

/**
 * Bird's move method using three coordinates
 * @param x
 * @param y
 * @param z for flying
 */
void Bird::move(double x, double y, double z) {
    Animal::move(x, y, z);
    std::cout << "Bird [ID: " << this->uniqueID << "] moved to (" << this->coordinate.x << ", " << this->coordinate.y << ", " << this->coordinate.z << ")" << std::endl;
}

/**
 * Bird's sleep method
 * @param uniqueID
 */
void Bird::sleep() const {
    if (isAlive) {
        std::cout << "Bird [ID: " << this->uniqueID << "] is sleeping." << std::endl;
        return;
    } else {
        std::cout << "Bird [ID:" << this->uniqueID << "]is dead." << std::endl;
    }
}

/**
 * Bird's eat method
 * @param uniqueID
 */
void Bird::eat() const {
    if (isAlive) {
        std::cout << "Bird [ID: " << this->uniqueID << "] is eating." << std::endl;
        return;
    } else {
        std::cout << "Bird [ID:" << this->uniqueID << "]is dead." << std::endl;
    }

}

/**
 * Bird's overloaded insertion operator
 *
 * @param os
 * @param bird
 * @return
 */
std::ostream &operator<<(std::ostream &os, const Bird &bird) {
    os  << "Bird: [age=" << bird.age << ", id=" << bird.uniqueID << ", alive=" << bird.isAlive
        << ", location(" << bird.coordinate.x << ", " << bird.coordinate.y
        << ", " << bird.coordinate.z << ")]" ;
    return os;
}
