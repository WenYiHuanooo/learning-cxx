#include "../exercise.h"

// C++ 中，`class` 和 `struct` 之间的**唯一区别**是
// `class` 默认访问控制符是 `private`，
// `struct` 默认访问控制符是 `public`。
// READ: 访问说明符 <https://zh.cppreference.com/w/cpp/language/access>

// 这个 class 中的字段被 private 修饰，只能在 class 内部访问。
// 因此必须提供构造器来初始化字段。
// READ: 构造器 <https://zh.cppreference.com/w/cpp/language/constructor>
class Fibonacci {
    size_t cache[16];
    int cached;

public:
    // 实现构造器，初始化 cache 数组和 cached 变量
    Fibonacci() : cached(-1) {
        std::fill(cache, std::end(cache), 0); // 初始化 cache 数组为 0
    }

    size_t get(int i) {
        if (cached < i) {
            for (int n = std::max(cached + 1, 0); n <= i; ++n) {
                if (n < 2) {
                    cache[n] = n; 
                } else {
                    cache[n] = cache[n - 1] + cache[n - 2];
                }
            }
            cached = i; 
        }
        return cache[i];
    }
};

int main(int argc, char **argv) {

    Fibonacci fib;
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}
