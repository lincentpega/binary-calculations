#include "correct_input.h"


bool is_number(const std::string &s) {
    std::string::const_iterator it = s.begin();
    if (*it == '-')
        ++it;
    while (it != s.end() && std::isdigit(*it))
        ++it;
    if (!s.empty() && it == s.end())
        return true;
    else
        return false;
}

bool is_oper(const std::string &s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && (*it == ' ' || *it == '+' || *it == '-' || *it == '*'))
        ++it;
    if (!s.empty() && it == s.end())
        return true;
    else return false;
}

int correct_input(){
    std::string a;
    std::getline(std::cin, a);
    while(!is_number(a)){
        std::cerr << "Incorrect value. Enter again: " << std::endl;
        getline(std::cin, a);
    }
    return std::stoi(a);
}

char correct_oper(){
    std::string a;
    std::getline(std::cin, a);
    while(!is_oper(a)){
        std::cerr << "Incorrect value. Enter again: " << std::endl;
        getline(std::cin, a);
    }
    return a[0];
}