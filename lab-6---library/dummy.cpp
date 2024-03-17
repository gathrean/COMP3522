//
// Created by Gathrean Dela Cruz on 2023-10-24.
//

#include <iostream>

using namespace std;

class A {
public:
    A() { cout << "Default constructor!" << endl; }

    ~A() { cout << "Default destructor!" << endl; }

    A(const A&) { cout << "Copy constructor!" << endl; }
};

A foo(A input)
{
    cout << "Look ma, I'm fooing!" << endl;
    return input;
}

int main()
{
    A littleA;
    foo(littleA);
    A anotherA = littleA;
    A yetAnotherA = foo(littleA);
}