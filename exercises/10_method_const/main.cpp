#include "../exercise.h"

struct Fibonacci {
    int numbers[11];

    int get(int i) const {
        return numbers[i]; 
    }
};

int main(int argc, char **argv) {
    // 使用 constexpr 声明 FIB 对象，它将在编译时初始化
    constexpr Fibonacci FIB{0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
    ASSERT(FIB.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << FIB.get(10) << std::endl;
    return 0;
}
