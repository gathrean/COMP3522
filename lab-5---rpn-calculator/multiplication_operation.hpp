//
// Created by Gathrean Dela Cruz on 2023-10-02.
//

#pragma once

#include "abstract_operation.hpp"

class Multiplication_Operation : public Abstract_Operation {
public:
    const static char MULTIPLICATION_CODE = '*';

    // Passes '*' to the Abstract_Operation constructor
    Multiplication_Operation() : Abstract_Operation(MULTIPLICATION_CODE) {}

    // Performs multiplication
    int perform(int a, int b) override { return a * b; }

    ~Multiplication_Operation() override = default;
};

