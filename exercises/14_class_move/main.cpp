#include <cassert>
#include <cstring> 
#include "../exercise.h" 

class DynFibonacci {
    size_t *cache;
    int cached;

public:
    // 实现动态设置容量的构造器
    DynFibonacci(int capacity) : cache(new size_t[capacity]), cached(0) {
        if (capacity > 0) {
            cache[0] = 0;
            if (capacity > 1) {
                cache[1] = 1;
            }
        }
    }

    // 实现移动构造器
    DynFibonacci(DynFibonacci &&other) noexcept 
        : cache(other.cache), cached(other.cached) {
        other.cache = nullptr; // 将资源转移后，原对象的缓存指针设为nullptr
        other.cached = 0;
    }

    // 实现移动赋值运算符
    DynFibonacci &operator=(DynFibonacci &&other) noexcept {
        if (this != &other) {
            delete[] cache; // 释放当前对象的资源
            cache = other.cache; // 接收移动构造器转移的资源
            cached = other.cached; // 接收移动构造器转移的已缓存值的数量
            other.cache = nullptr; // 将原对象的缓存指针设为nullptr
            other.cached = 0;
        }
        return *this;
    }

    // 实现析构器，释放缓存空间
    ~DynFibonacci() {
        delete[] cache;
    }

    // 实现正确的缓存优化斐波那契计算
    size_t operator()(int i) {
        if (i < 0) {
            ASSERT(false, "Negative index is not allowed");
            return 0;
        }
        for (; cached < i; ++cached) {
            cache[cached] = (cached > 1 ? cache[cached - 2] + cache[cached - 1] : cached);
        }
        return cache[i];
    }

    bool is_alive() const {
        return cache != nullptr;
    }
};
int main(int argc, char **argv) {
    DynFibonacci fib(12);
    ASSERT(fib(10) == 55, "fibonacci(10) should be 55");

    DynFibonacci fib_ = std::move(fib);
    ASSERT(!fib.is_alive(), "Object moved from should be dead");
    ASSERT(fib_.is_alive(), "Object moved to should be alive");
    ASSERT(fib_(10) == 55, "fibonacci(10) should be 55");

    DynFibonacci fib0(6);
    DynFibonacci fib1(12);
    fib0 = std::move(fib1);
    ASSERT(!fib1.is_alive(), "fib1 should not be alive after move");
    ASSERT(fib0.is_alive(), "fib0 should be alive after move");
    ASSERT(fib0(10) == 55, "fibonacci(10) should be 55");

    fib0 = std::move(fib0); // Moving from itself should be a no-op
    ASSERT(fib0.is_alive(), "fib0 should still be alive after self-move");
    ASSERT(fib0(10) == 55, "fibonacci(10) should be 55");

    return 0;
}
