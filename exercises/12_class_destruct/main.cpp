#include "../exercise.h"

// READ: 析构函数 <https://zh.cppreference.com/w/cpp/language/destructor>

/// @brief 任意缓存容量的斐波那契类型。
/// @details 可以在构造时传入缓存容量，因此需要动态分配缓存空间。
class DynFibonacci {
    size_t *cache;
    int cached;

public:
    // 实现动态设置容量的构造器
    DynFibonacci(int capacity) : cache(new size_t[capacity]), cached(-1) {
        // 初始化缓存空间，-1 表示尚未计算任何斐波那契数
    }

    // 实现析构器，释放缓存空间
    ~DynFibonacci() {
        delete[] cache; // 释放动态分配的内存
    }

    // 实现正确的缓存优化斐波那契计算
    size_t get(int i) {
        if (i < 0) return 0; // 负数没有斐波那契数
        if (cached < i) {
            for (int n = cached + 1; n <= i; ++n) {
                if (n < 2) {
                    cache[n] = n; // 第0和第1个斐波那契数是0和1
                } else {
                    cache[n] = cache[n - 1] + cache[n - 2];
                }
            }
            cached = i; // 更新 cached 变量
        }
        return cache[i];
    }
};

int main(int argc, char **argv) {
    DynFibonacci fib(12);
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}
