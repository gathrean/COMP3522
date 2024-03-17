//
// Created by Gathrean Dela Cruz on 2023-09-21.
//
#include "myStack.hpp"

using namespace std;

MyStack::MyStack() {
    topIndex = -1;
}

// Question 12
bool MyStack::isEmpty() const {
    return (topIndex == -1);
}

// Question 13
bool MyStack::isFull() const {
    return (topIndex == MAX_SIZE - 1);
}

int MyStack::push(int value) {
    if (!isFull()) {
        stack[++topIndex] = value;
        return 1;
    } else {
        return 0;
    }
};

int MyStack::pop() {
    if (!isEmpty()) {
        --topIndex;
        return 1;
    } else {
        return 0;
    }
}

int MyStack::top() const {
    if (!isEmpty()) {
        return stack[topIndex];
    } else {
        return 0;
    }
}

string MyStack::print() const {
    string result;
    for (int i = 0; i <= topIndex; ++i) {
        result += to_string(stack[i]) + " ";
    }
    return result;
}