//
// Created by Gathrean Dela Cruz on 2023-10-02.
//

#pragma once

/**
 * Operation Interface
 */
class Operation {
public:

    virtual char get_code() = 0;

    virtual int perform(int a, int b) = 0;

    virtual ~Operation() = default;

};