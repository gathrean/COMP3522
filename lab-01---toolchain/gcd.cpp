//
// Created by Gathrean Dela Cruz on 2023-09-07.
//

#include "gcd.hpp"
int gcd(int a, int b) {
    while (a != b) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}