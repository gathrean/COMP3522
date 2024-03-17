//
// Created by Gathrean Dela Cruz on 2023-10-03.
//

#include "rpn_calculator.hpp"

RPNCalculator::RPNCalculator() : result(0) {}

void RPNCalculator::perform(Operation* operation) {
    int b = stack.top();
    stack.pop();
    int a = stack.top();
    stack.pop();
    result = operation->perform(a, b);
    stack.push(result);
}

Operation* RPNCalculator::operation_type(char operation) {
    switch (operation) {
        case Addition_Operation::ADDITION_CODE:
            return new Addition_Operation;
        case Subtraction_Operation::SUBTRACTION_CODE:
            return new Subtraction_Operation;
        case Multiplication_Operation::MULTIPLICATION_CODE:
            return new Multiplication_Operation;
        case Division_Operation::DIVISION_CODE:
            return new Division_Operation;
        default:
            throw std::invalid_argument("Invalid operation: " + std::string(1, operation));
    }
}

int RPNCalculator::process_formula(std::string formula) {
    std::istringstream iss(formula);
    std::string token;
    Operation* op;

    while (iss >> token) {
        if (isdigit(token[0])) {
            stack.push(std::stoi(token));
        } else {
            op = operation_type(token[0]);
            perform(op);
            delete op;
        }
    }
    return result;
}