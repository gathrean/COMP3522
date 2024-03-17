//Name: Gathrean Dela Cruz
//Student# : A01167248

#include <iostream>
#include "gcd.hpp"

int main() {
    int a, b;

    std::cout << "Lab 1, Hello everyone!" << std::endl;
    std::cout << "Enter first number: ";

    std::cin >> a;

    std::cout << "Enter second number: ";

    std::cin >> b;

    int result = gcd(a, b);

    std::cout << "HCF = " << result;

    return 0;
}
