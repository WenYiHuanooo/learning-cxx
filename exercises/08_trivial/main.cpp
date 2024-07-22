#include "../exercise.h"

struct FibonacciCache {
    unsigned long long cache[16]; // 存储斐波那契数的缓存
    int cached; 

    // 初始化所有斐波那契数为0，cached为0
    FibonacciCache() : cache{}, cached(0) {}
};

static unsigned long long fibonacci(FibonacciCache &cache, int i) {
    if (cache.cached >= i) {
        return cache.cache[i]; // 如果已经计算过，直接返回缓存中的值
    }

    for (int n = cache.cached; n <= i; ++n) {
        if (n < 2) {
            cache.cache[n] = n; // 第0和第1个斐波那契数是0和1
        } else {
            cache.cache[n] = cache.cache[n - 1] + cache.cache[n - 2];
        }
    }
    cache.cached = i; // 更新缓存的最大索引
    return cache.cache[i];
}

int main(int argc, char **argv) {
    // 初始化缓存结构体
    FibonacciCache fib;
    ASSERT(fibonacci(fib, 10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fibonacci(fib, 10) << std::endl;
    return 0;
}
