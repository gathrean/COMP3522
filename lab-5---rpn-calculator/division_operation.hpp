//
// Created by Gathrean Dela Cruz on 2023-10-02.
//

#pragma once

#include "abstract_operation.hpp"

class Division_Operation : public Abstract_Operation {
public:
    const static char DIVISION_CODE = '/';

    // Passes '/' to the Abstract_Operation constructor
    Division_Operation() : Abstract_Operation(DIVISION_CODE) {}

    // Performs division
    int perform(int a, int b) override{ return a / b; }

    ~Division_Operation() override = default;
};
