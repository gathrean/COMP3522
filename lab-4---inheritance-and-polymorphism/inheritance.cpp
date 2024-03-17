//
// Created by Gathrean Dela Cruz on 2023-09-25.
//

// Name : Gathrean Dela Cruz
// Student ID : A01167248

#include <iostream>
#include "animal.hpp"
#include "bird.hpp"
#include "canine.hpp"

using namespace std;

int main() {
    cout << "---Create all animals---" << endl;
    Animal *animalPtr = new Animal(); // new animal object with dynamic memory
    Bird *birdPtr = new Bird(); // new bird object with dynamic memory
    Canine *caninePtr = new Canine(); // new canine object with dynamic memory

    cout << "\n---Print all animals---" << endl;
    cout << *animalPtr << endl;
    cout << *((Bird *) birdPtr) << endl;
    cout << *((Canine *) caninePtr) << endl;

    cout << "\n---Make all animals move and print---" << endl;
    animalPtr->move(1, 1, 0);
    birdPtr->move(4, 2, 0);
    caninePtr->move(4, 5, 0);
    caninePtr->move(4, 3, 0);

    cout << "\n---Make all animals sleep---" << endl;
    animalPtr->sleep();
    birdPtr->sleep();
    caninePtr->sleep();

    cout << "\n---Make all animals eat---" << endl;
    animalPtr->eat();
    birdPtr->eat();
    caninePtr->eat();

    cout << "\n---Make canine hunt bird---" << endl;
    birdPtr->move(5, 6, 0);
    caninePtr->move(5, 6, 0);
    caninePtr->hunt(birdPtr); // Should get killed

    cout << "\n---Make all animals at end---" << endl;
    cout << *animalPtr << endl;
    cout << *((Bird *) birdPtr) << endl;
    cout << *((Canine *) caninePtr) << endl;

    cout << "\n---Delete dynamic memory---" << endl;
    delete animalPtr;
    delete birdPtr;
    delete caninePtr;
    return 0;
}