//
// Created by Gathrean Dela Cruz on 2023-09-29.
//

#ifndef LAB4TEMPLATE_CANINE_HPP
#define LAB4TEMPLATE_CANINE_HPP

#include "animal.hpp" // parent class

class Canine : public Animal {
public:
    // Default Constructor
    Canine();

    // Constructor with three parameters
    Canine(int age, double x, double y);

    // Copy constructor
    Canine(const Canine &canine);

    // Virtual destructor
    ~Canine() override;

    // Canine move method
    void move(double x, double y) override;

    void move(double x, double y, double z) override;

    void sleep() const override;

    void eat() const override;

//    void hunt(Animal *animal);

// Non-virtual member function specific to Canine
    void hunt(Animal *animal);

    friend std::ostream &operator<<(std::ostream &os, const Canine &canine);
};

#endif //LAB4TEMPLATE_CANINE_HPP
