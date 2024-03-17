//
// Created by Gathrean Dela Cruz on 2023-10-02.
//

#pragma once

#include "operation.hpp"

/**
 * Abstract Operation Class
 */
class Abstract_Operation : public Operation {
private:

    char operation_type;

public:

    Abstract_Operation(char operation_type) {
        this->operation_type = operation_type;
    }

    char get_code() override {
        return operation_type;
    }

    virtual ~Abstract_Operation() = default;
};
