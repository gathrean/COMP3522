//
// Created by Gathrean Dela Cruz on 2023-09-21.
//

#ifndef LAB3TEMPLATE_MYSTACK_HPP
#define LAB3TEMPLATE_MYSTACK_HPP

#include <iostream>

using namespace std;

class MyStack {
public:
    // Q7: C-style array of max size 10
    static constexpr int MAX_SIZE = 10;

    MyStack(); // Constructor

    // Member functions
    int push(int value); // Question 9
    int pop(); // Question 10
    bool isEmpty() const;
    bool isFull() const;
    int top() const; // Question 11
    string print() const;
private:
    int stack[MAX_SIZE]{};
    int topIndex;
};

#endif //LAB3TEMPLATE_MYSTACK_HPP
