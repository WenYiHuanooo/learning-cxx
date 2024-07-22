#include "../exercise.h"

struct Fibonacci {
    unsigned long long cache[128];
    int cached;

     Fibonacci() : cached(0) {
        for (int i = 0; i < 128; ++i) {
            cache[i] = 0; // 初始化缓存数组
        }
    }

    unsigned long long Fibonacci::get(int i) {
    if (i <= cached) {
        return cache[i];
    }

    for (int n = cached; n <= i; ++n) {
        if (n < 2) {
            cache[n] = n; 
        } else {
            cache[n] = cache[n - 1] + cache[n - 2];
        }
    }
    cached = i; 
    return cache[i];
}
};

int main(int argc, char **argv) {
    // TODO: 初始化缓存结构体，使计算正确
    Fibonacci fib;
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}
