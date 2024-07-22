#include "../exercise.h"
#include <cassert>
#include <cmath> // 引入cmath库，用于处理浮点数比较

// 函数模板化
template<typename T>
T plus(T a, T b) {
    return a + b;
}

int main(int argc, char **argv) {
    ASSERT(plus(1, 2) == 3, "Plus two int");
    ASSERT(plus(1u, 2u) == 3u, "Plus two unsigned int");

    // 浮点数比较
    ASSERT(plus(1.25f, 2.5f) == 3.75f, "Plus two float");
    ASSERT(plus(1.25, 2.5) == 3.75, "Plus two double");

    // 浮点数加法可能存在精度问题，使用差值比较
    float sum = plus(0.1f, 0.2f);
    ASSERT(std::fabs(sum - 0.3f) < 1e-6, "How to make this pass?");
    
    return 0;
}
