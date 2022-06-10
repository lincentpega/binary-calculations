#include <iostream>
#include <bitset>
#include <vector>

#include "binary_number.h"
#include "correct_input.h"

const int bitness = 8;

int main() {
    std::cout << "Enter two numbers: " << std::endl;
    int a = correct_input();
    int b = correct_input();
    std::cout << "Enter operator: " << std::endl;
    char oper = correct_oper();

    BinaryNumber num1{a, bitness};
    BinaryNumber num2{b, bitness};


    BinaryNumber sum = num1 + num2;
    BinaryNumber sub = num1 - num2;
    BinaryNumber mult = num1 * num2;

    std::cout << num1 << ' ' << oper << ' ' << num2 << std::endl;

    switch (oper) {
        case '+':
        {
            std::cout << "Sum bin: " << sum << ", dec: " << sum.to_decimal() << std::endl;
            break;
        }
        case '-':
        {
            std::cout << "Sub bin: " << sub << ", dec: " << sub.to_decimal() << std::endl;
            break;
        }
        case '*':
        {
            std::cout << "Mult bin: " << mult << ", dec: " << mult.to_decimal() << std::endl;
            break;
        }
        default:
            std::cerr << "Invalid operator" << std::endl;
    }

    return 0;
}
