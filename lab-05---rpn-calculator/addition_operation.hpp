//
// Created by Gathrean Dela Cruz on 2023-10-02.
//

#pragma once

#include "abstract_operation.hpp"

class Addition_Operation : public Abstract_Operation {
public:
    const static char ADDITION_CODE = '+';

    // Passes '+' to the Abstract_Operation constructor
    Addition_Operation() : Abstract_Operation(ADDITION_CODE) {}

    // Performs addition
    int perform(int a, int b) override { return a + b; }

    ~Addition_Operation() override = default;
};
