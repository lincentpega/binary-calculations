#ifndef ALGORITHMS_LAB2_BINARY_NUMBER_H
#define ALGORITHMS_LAB2_BINARY_NUMBER_H

#include <iostream>
#include <bitset>
#include <vector>

int pow(int a, int b);

class BinaryNumber {
private:
    int *m_bin_dump;
    int m_bitness;
    bool m_negative_flag = false; // true - "+", false - "-"
    void setDump(int number);

public:
    BinaryNumber() {
        m_bin_dump = nullptr;
        m_bitness = 0;
    }

    BinaryNumber(const BinaryNumber &n) : m_bitness(n.m_bitness), m_negative_flag(n.m_negative_flag){
        m_bin_dump = new (std::nothrow) int[m_bitness];
        for (int i = 0; i < m_bitness; ++i){
            m_bin_dump[i] = n.m_bin_dump[i];
        }
    }

    BinaryNumber(int number, int bitness) : m_bitness(bitness) {
        if (number > pow(2, bitness)){
            std::cerr << "You can not keep so large number in this array with this bitness";
            exit(2);
        }
        m_bin_dump = new(std::nothrow) int[m_bitness]{};
        if (!m_bin_dump) {
            std::cerr << "Memory allocating error";
            m_bitness = 0;
        } else {
            setDump(number);
        }
    }

    BinaryNumber(const int *const arr, int size) : m_bitness(size){
        m_bin_dump = new(std::nothrow) int [m_bitness]{};
        if (!m_bin_dump) {
            std::cerr << "Memory allocating error";
            m_bitness = 0;
        } else {
            setDump(arr, size);
        }
    }

    ~BinaryNumber() {
        if (m_bin_dump) {
            delete[] m_bin_dump;
            m_bin_dump = nullptr;
        }
    }

    void setDump(const int *arr, int size);

    int getBite(int number) const;

    int getBitness() const { return m_bitness; }

    bool isNegative() const { return m_negative_flag; }

    void reverse_dump();

    void print_decimal() const;

    friend BinaryNumber operator+(BinaryNumber &n1, BinaryNumber &n2);
//    friend BinaryNumber operator+(BinaryNumber &n1, int n2);
//    friend BinaryNumber operator+(int n1, BinaryNumber &n2);

    friend std::ostream &operator<<(std::ostream &out, const BinaryNumber &bin_number);

};

#endif //ALGORITHMS_LAB2_BINARY_NUMBER_H
