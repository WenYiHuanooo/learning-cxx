#include "../exercise.h"

#include <iostream>
#include <stdexcept>

#define ASSERT(condition, message) \
    if (!(condition)) { \
        std::cerr << "Assertion failed: " << message << ", function " \
                  << __FUNCTION__ << ", file " << __FILE__ << ", line " << __LINE__ << std::endl; \
        throw std::runtime_error(message); \
    }

// 声明 add 函数
int add(int a, int b);

int main(int argc, char **argv) {
    ASSERT(add(123, 456) == 123 + 456, "add(123, 456) should be 123 + 456");

    auto x = 1, y = 2;
    std::cout << x << " + " << y << " = " << add(x, y) << std::endl;
    return 0;
}

// 定义 add 函数
int add(int a, int b) {
    return a + b;
}
