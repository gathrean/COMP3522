//
// Created by Gathrean Dela Cruz on 2023-09-25.
//

#ifndef LAB4TEMPLATE_BIRD_HPP
#define LAB4TEMPLATE_BIRD_HPP

#include "animal.hpp" // the base class
#include <iostream>

class Bird : public Animal {

public:
    // Default Constructor
    Bird();

    // Constructor with four parameters
    Bird(int age, double x, double y, double z);

    // Copy constructor
    Bird(const Bird &bird);

    // Virtual Destructor
    ~Bird() override;

    // Override move method
    void move(double x, double y, double z) override;

    // Bird sleep method
    void sleep() const override;

    // Bird eat method
    void eat() const override;

    // Overload the insertion operator (<<)
    friend std::ostream& operator<<(std::ostream& os, const Bird& bird);
};

#endif //LAB4TEMPLATE_BIRD_HPP
