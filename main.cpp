#include <iostream>
#include <bitset>
#include <vector>

#include "binary_number.h"


int main() {
//    std::cout << "Enter two numbers separated by space: " << std::endl;
//    int a, b;
//    std::cin >> a >> b;
//    std::cout << "Enter their sizes in bits respectively: " << std::endl;
//    int bitness1, bitness2;
//    std::cin >> bitness1 >> bitness2;

    BinaryNumber num1{10, 8};
    BinaryNumber num2{-5, 16};

    BinaryNumber sum = num1 + num2;
    BinaryNumber sub = num1 - num2;
    BinaryNumber mult = num1 * num2;
    std::cout << "Sum bin: " << sum << ", dec: " << sum.to_decimal() << std::endl;
    std::cout << "Sub bin: " << sub << ", dec: " << sub.to_decimal() << std::endl;
    std::cout << "Mult bin: " << mult << ", dec: " << mult.to_decimal() << std::endl;

    return 0;
}
