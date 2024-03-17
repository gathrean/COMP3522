//
// Created by Gathrean Dela Cruz on 2023-09-22.
//
#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() put this in one cpp file

#include "catch.hpp"
#include "myStack.hpp"

TEST_CASE("A new stack is empty", "testTag0") {
    MyStack tester;
    REQUIRE(tester.isEmpty() == true);
    REQUIRE(tester.isFull() == false);
}

// Test 1: "Pop an empty stack"
TEST_CASE("Pop empty stack", "testTag1") {
    MyStack s;

    // popping an element when it's empty, should tell us it's empty (0).
    REQUIRE(s.pop() == 0);

    // Makes sure that my stack is still empty
    REQUIRE(s.isEmpty());
}

// Test 2: Pop empty stack then add values
TEST_CASE("Pop empty stack, then add values", "testTag2"){
    MyStack s;

    // popped an empty stack
    REQUIRE(s.pop() == 0);

    // added value
    s.push(1);

    // checking if the 1 value I pushed is actually in the stack.
    REQUIRE(s.pop() == 1);
}

// Test 3: Push more than maximum stack amount, check value of top of stack
TEST_CASE("Push more than max, then check value", "testTag3") {
    MyStack s;

    // This should fill the stack to its max size
    for (int i = 0; i < MyStack::MAX_SIZE; i++) {
        REQUIRE(s.push(i) == 1);
    }

    // This should return 0, which means that result failed to add more to the full stack
    int result = s.push(37);
    REQUIRE(result == 0);

    REQUIRE(s.top() == MyStack::MAX_SIZE - 1);
}

// Test 4: Check top value on empty stack
TEST_CASE("Check top value of empty stack", "testTag4"){
    MyStack stack;
    REQUIRE(stack.isEmpty());

    int topValue = stack.top();
    REQUIRE(topValue == 0);
}

// Test 5: Push X values pop Y values, check top for expected value
TEST_CASE("Push X values pop Y values, check top for expected value", "testTag5"){
    MyStack stack;

    // Push X values
    int X = 5;
    for (int i = 1; i <= X; i++){
        REQUIRE(stack.push(i) == 1);
    }

    // Pop Y values
    int Y = 3;
    for (int i = 1; i <= Y; i++){
        REQUIRE(stack.pop() == 1);
    }

    int expectedValue = X - Y;
    REQUIRE(stack.top() == expectedValue);
}

// Test 6: Push exactly 10 values, check if stack is full and top value is expected value
TEST_CASE("Push exactly 10 values, check if stack is full", "testTag6"){
    MyStack stack;

    // This should fill the stack to its max size
    for (int i = 1; i <= MyStack::MAX_SIZE; i++) {
        REQUIRE(stack.push(i) == 1);
    }

    int topValue = stack.top();

    REQUIRE(topValue == MyStack::MAX_SIZE - 1);
}