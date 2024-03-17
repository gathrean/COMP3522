//
// Created by Gathrean Dela Cruz on 2023-10-02.
//

#pragma once

#include "operation.hpp"
#include "abstract_operation.hpp"
#include "addition_operation.hpp"
#include "subtraction_operation.hpp"
#include "multiplication_operation.hpp"
#include "division_operation.hpp"
#include <stack>
#include <string>
#include <sstream>

class RPNCalculator {

private:
    int result;
    std::stack<int> stack;
    void perform(Operation* operation);

public:
    RPNCalculator();
    Operation* operation_type(char operation);
    int process_formula(std::string formula);
};