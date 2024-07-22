#include <cassert>
#include "../exercise.h" 

class DynFibonacci {
    size_t *cache;
    int cached;

public:
    DynFibonacci(int capacity): cache(new size_t[capacity]), cached(0) {}

    DynFibonacci(DynFibonacci const &other): cache(new size_t[other.cached]), cached(other.cached) {
        for (int i = 0; i <= cached; ++i) {
            cache[i] = other.cache[i];
        }
    }

    // 实现析构器，释放缓存空间
    ~DynFibonacci() {
        delete[] cache;
    }

    // 实现正确的缓存优化斐波那契计算
    size_t get(int i) {
        if (i <= cached) {
            return cache[i];
        }
        if (cached < 2) {
            cache[0] = 0;
            cache[1] = 1;
        }
        for (int j = cached + 1; j <= i; ++j) {
            cache[j] = cache[j - 1] + cache[j - 2];
        }
        cached = i;
        return cache[i];
    }

    // 重载方法，与非const方法区别在于不能修改对象的成员变量
    size_t get(int i) const {
        if (i <= cached) {
            return cache[i];
        }
        assert(false); // 由于是const方法，不能调用ASSERT宏
    }
};

int main(int argc, char **argv) {
    DynFibonacci fib(12);
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    DynFibonacci const fib_ = fib;
    ASSERT(fib_.get(10) == fib.get(10), "Object cloned");
    return 0;
}
