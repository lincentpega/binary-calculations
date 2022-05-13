#include "binary_number.h"
#include <cmath>
#include <vector>

int reverse_bin(int i) {
    if (i == 0) {
        return 1;
    } else {
        return 0;
    }
}

int pow(int a, int b) {
    int result = 1;
    for (int i = 0; i < b; ++i) {
        result *= a;
    }
    return result;
}

void BinaryNumber::setDump(int number) {
    if (number < 0) {
        m_negative_flag = true;
        number = -number - 1;
        for (int i = 0; i < m_bitness; ++i) {
            if (number % 2) {
                m_bin_dump[i] = 0;
            } else {
                m_bin_dump[i] = 1;
            }
            number /= 2;
        }
    } else {
        m_negative_flag = false;
        for (int i = 0; i < m_bitness; ++i) {
            m_bin_dump[i] = number % 2;
            number /= 2;
        }
    }
}

void BinaryNumber::setDump(const int *const arr, int size) {
    if (arr[size-1] == 1)
        m_negative_flag = false;
    else
        m_negative_flag = true;
    for (int i = 0; i < size; ++i){
        m_bin_dump[i] = arr[i];
    }
}

int BinaryNumber::getBite(int number) const {
    if (number > m_bitness) {
        if (m_negative_flag)
            return 1;
        else
            return 0;
    } else {
        return m_bin_dump[number];
    }
}

void BinaryNumber::reverse_dump() {
    for (int i = 0; i < m_bitness; ++i) {
        if (m_bin_dump[i] == 0)
            m_bin_dump[i] = 1;
        else
            m_bin_dump[i] = 0;
    }
}

void BinaryNumber::print_decimal() const {
    int result = 0;
    BinaryNumber tmp_number1{m_bin_dump, m_bitness};


    if (!tmp_number1.m_negative_flag){ // if negative
        std::cout << "-";
        tmp_number1.reverse_dump();

    }
    BinaryNumber tmp_number_2{1, tmp_number1.getBitness()};
    BinaryNumber sum_result{(tmp_number1 + tmp_number_2).m_bin_dump, (tmp_number1 + tmp_number_2).m_bitness};
    for (int i = 0; i < this->getBitness(); ++i){
        result += sum_result.getBite(i) * pow(2, i);
    }
    std::cout << result << std::endl;
}

std::ostream &operator<<(std::ostream &out, const BinaryNumber &bin_number) {
    for (int i = bin_number.getBitness() - 1; i >= 0; --i) {
        out << bin_number.getBite(i);
    }

    return out;
}

BinaryNumber operator+(BinaryNumber &n1, BinaryNumber &n2) {
    int new_bitness = (n1.m_bitness > n2.m_bitness ? n1.m_bitness : n2.m_bitness);
    int *tmp_arr = new (std::nothrow) int[new_bitness]{};

    int carry = 0;
    for (int i = 0; i < new_bitness; ++i) {
        int sum_of_digits = n1.getBite(i) + n2.getBite(i);
        if (sum_of_digits + carry == 0){
            tmp_arr[i] = 0;
            carry = 0;
        }
        else if (sum_of_digits + carry == 1){
            tmp_arr[i] = 1;
            carry = 0;
        }
        else if (sum_of_digits + carry == 2){
            tmp_arr[i] = 0;
            carry = 1;
        }
        else if (sum_of_digits + carry == 3){
            tmp_arr[i] = 1;
            carry = 1;
        }
    }
    if (carry && tmp_arr[new_bitness - 1] != 1){
        std::cerr << "Overflow, numbers is too large";
        delete[] tmp_arr;
        tmp_arr = nullptr;
        exit(1);
    }

    BinaryNumber new_number{tmp_arr, new_bitness};

    delete[] tmp_arr;
    tmp_arr = nullptr;

    return new_number;
}

//BinaryNumber operator+(BinaryNumber &n1, int n2) {
//    int new_bitness = n1.getBitness();
//    int *tmp_arr = new (std::nothrow) int[new_bitness]{};
//
//    int carry = 0;
//    for (int i = 0; i < new_bitness; ++i) {
//        int sum_of_digits = n1.getBite(i) + (n2 % 2);
//        n2 /= 2;
//        if (sum_of_digits + carry == 0){
//            tmp_arr[i] = 0;
//            carry = 0;
//        }
//        else if (sum_of_digits + carry == 1){
//            tmp_arr[i] = 1;
//            carry = 0;
//        }
//        else if (sum_of_digits + carry == 2){
//            tmp_arr[i] = 0;
//            carry += 1;
//        }
//        else if (sum_of_digits + carry == 3){
//            tmp_arr[i] = 1;
//            carry += 1;
//        }
//    }
//    if (carry){
////        std::cerr << "Overflow, numbers is too large";
////        delete[] tmp_arr;
////        tmp_arr = nullptr;
////        exit(1);
//    }
//
//    BinaryNumber new_number{tmp_arr, new_bitness};
//
//    delete[] tmp_arr;
//    tmp_arr = nullptr;
//
//    return new_number;
//}

//BinaryNumber operator+(int n1, BinaryNumber &n2) {
//    int new_bitness = n2.getBitness();
//    int *tmp_arr = new (std::nothrow) int[new_bitness]{};
//
//    int carry = 0;
//    for (int i = 0; i < new_bitness; ++i) {
//        int sum_of_digits = n2.getBite(i) + (n1 % 2);
//        n1 /= 2;
//        if (sum_of_digits + carry == 0){
//            tmp_arr[i] = 0;
//            carry = 0;
//        }
//        else if (sum_of_digits + carry == 1){
//            tmp_arr[i] = 1;
//            carry = 0;
//        }
//        else if (sum_of_digits + carry == 2){
//            tmp_arr[i] = 0;
//            carry += 1;
//        }
//        else if (sum_of_digits + carry == 3){
//            tmp_arr[i] = 1;
//            carry += 1;
//        }
//    }
//    if (carry){
////        std::cerr << "Overflow, numbers is too large";
////        delete[] tmp_arr;
////        tmp_arr = nullptr;
////        exit(1);
//    }
//
//    BinaryNumber new_number{tmp_arr, new_bitness};
//
//    delete[] tmp_arr;
//    tmp_arr = nullptr;
//
//    return new_number;
//}