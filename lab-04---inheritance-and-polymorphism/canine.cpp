//
// Created by Gathrean Dela Cruz on 2023-09-29.
//
#include "canine.hpp"

const int INT_ZERO = 0;
const double DBL_ZERO = 0.0;
//long Animal::uniqueID = 0;

/**
 * Default constructor for Canine
 *
 * @param age
 * @param isAlive
 * @param x
 * @param y
 * @param uniqueId
 */
Canine::Canine() : Animal() {
    age = INT_ZERO;
    isAlive = true;
    coordinate.x = DBL_ZERO;
    coordinate.y = DBL_ZERO;
    uniqueID = uniqueID++;
    std::cout << "Constructing a Canine object [ID: " << uniqueID << "]" << std::endl;
}

/**
 * Constructor with 3 parameters
 *
 * @param age
 * @param x
 * @param y
*/
Canine::Canine(int age, double x, double y) : Animal() {
    this->age = age;
    coordinate.x = DBL_ZERO;
    coordinate.y = DBL_ZERO;
    std::cout << "Constructing a Canine object [ID: " << this->uniqueID << "], with 3 parameters (age, x, y)"
              << std::endl;
}

/**
 * Copy constructor
 * @param canine
 */
Canine::Canine(const Canine &canine) {
    age = canine.age;
    isAlive = canine.isAlive;
    coordinate.x = canine.coordinate.x;
    coordinate.y = canine.coordinate.y;
    std::cout << "Constructing a Canine object [ID: " << this->uniqueID << "], with copy constructor" << std::endl;
}

/**
 * Virtual destructor
 * @param uniqueID
 */
Canine::~Canine() {
    std::cout << "Destructing a Canine object [ID: " << this->uniqueID << "]" << std::endl;
}

/**
 * Canine's move method using two coordinates
 *
 * @param x
 * @param y
 */
void Canine::move(double x, double y) {
    Animal::move(x, y);
    std::cout << "Canine [ID: " << this->uniqueID << "] moved to (" << this->coordinate.x << ", " << this->coordinate.y
              << ", " << this->coordinate.z << ")" << std::endl;
}

/**
 * Canine's move method using three coordinates
 *
 * @param x
 * @param y
 * @param z
 */
void Canine::move(double x, double y, double z) {
    Animal::move(x, y, z);
    std::cout << "Canine [ID: " << this->uniqueID << "] moved to (" << this->coordinate.x << ", " << this->coordinate.y
              << ", " << this->coordinate.z << ")" << std::endl;
}

/**
 * Canine sleep method
 *
 * @param isAlive bool
 * @param uniqueID int
 */
void Canine::sleep() const {
    if (isAlive) {
        std::cout << "Canine [ID: " << this->uniqueID << "] is sleeping." << std::endl;
        return;
    } else {
        std::cout << "Canine [ID: " << this->uniqueID << "]is dead." << std::endl;
        return;
    }
}

/**
 * Canine eat method
 *
 * @param isAlive bool
 * @param uniqueID int
 */
void Canine::eat() const {
    if (isAlive) {
        std::cout << "Canine [ID: " << this->uniqueID << "] is eating." << std::endl;
        return;
    } else {
        std::cout << "Canine [ID: " << this->uniqueID << "] is dead." << std::endl;
    }
}

/**
 * Canine hunt method
 *
 * @param animal
 */
void Canine::hunt(Animal *animal) {
    double distanceX, distanceY, distanceZ;
    int closeRange = 1;
    if (isAlive == 1 && animal->getAlive()) {

        // First, we need to get the distance between the two animals
        distanceX = abs(coordinate.x - animal->getX());
        distanceY = abs(coordinate.y - animal->getY());
        distanceZ = abs(coordinate.z - animal->getZ());

        // If the distance is less than or equal to 1, then the animal is close enough for canine to kill
        // Let's just say for this program, the kill is guaranteed.
        if ((distanceX <= closeRange
             && distanceY <= closeRange)
            || distanceZ <= closeRange) {
            std::cout << "Canine [ID: " << this->uniqueID << "] is hunting Animal [ID: " << animal->getID() << "]"
                      << std::endl;
            animal->setAlive(false);
            std::cout << "Animal [ID: " << animal->getID() << "] is killed." << std::endl;
            return;
        }
    } else {
        std::cout << "Canine [ID: " << this->uniqueID << "] failed to kill Animal of ID : " << animal->getID()
                  << std::endl;
    }
}

/**
 * Overloaded operator<< for Canine
 *
 * @param os
 * @param canine
 * @return
 */
std::ostream &operator<<(std::ostream &os, const Canine &canine) {
    os << "Canine: [age=" << canine.age << ", id=" << canine.uniqueID << ", alive=" << canine.isAlive
       << ", location(" << canine.coordinate.x << ", " << canine.coordinate.y
       << ", " << canine.coordinate.z << ")]";
    return os;
}