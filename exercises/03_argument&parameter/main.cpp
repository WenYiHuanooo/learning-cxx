#include "../exercise.h"

#include <iostream>
#include <stdexcept>

#define ASSERT(condition, message) \
    if (!(condition)) { \
        std::cerr << "Assertion failed: " << message << std::endl; \
        std::exit(EXIT_FAILURE); \
    }

void func(int param);

int main(int argc, char **argv) {
    auto arg = 99;
    ASSERT(arg == 99, "arg should be 99"); // 填写第一个 ASSERT
    std::cout << "before func call: " << arg << std::endl;
    func(arg);
    ASSERT(arg == 99, "arg should be 99"); // 填写第二个 ASSERT
    std::cout << "after func call: " << arg << std::endl;
    return 0;
}

void func(int param) {
    ASSERT(param == 99, "param should be 99"); // 填写第一个 ASSERT
    std::cout << "before add: " << param << std::endl;
    param += 1;
    ASSERT(param == 100, "param should be 100"); // 填写第二个 ASSERT
    std::cout << "after add: " << param << std::endl;
}
