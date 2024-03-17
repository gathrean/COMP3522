//
// Created by Gathrean Dela Cruz on 2023-10-02.
//

#pragma once

#include "abstract_operation.hpp"

class Subtraction_Operation : public Abstract_Operation {
public:
    const static char SUBTRACTION_CODE = '-';

    // Passes '-' to the Abstract_Operation constructor
    Subtraction_Operation() : Abstract_Operation(SUBTRACTION_CODE) {}

    // Performs subtraction
    int perform(int a, int b) override { return a - b; }

    ~Subtraction_Operation() override = default;
};

