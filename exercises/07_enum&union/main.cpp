#include "../exercise.h"
#include <iostream>
#include <cassert>
#define ASSERT(condition, message) \
    if (!(condition)) { \
        std::cerr << "Assertion failed: " << message << std::endl; \
        std::exit(EXIT_FAILURE); \
    }
enum ColorEnum : unsigned char {
    COLOR_RED = 31,
    COLOR_GREEN,
    COLOR_YELLOW,
    COLOR_BLUE,
};

// 有作用域枚举型是 C++ 引入的类型安全枚举。
// 其内部标识符需要带前缀引用，如 `Color::Red`。
// 作用域枚举型可以避免命名空间污染，并提供类型安全保证。
enum class Color : int {
    Red = COLOR_RED,
    Green,
    Yellow,
    Blue,
};

ColorEnum convert_by_pun(Color c) {
    // `union` 表示在同一内存位置存储的不同类型的值。
    // 其常见用法是实现类型双关转换，即将一种类型的值转换为另一种无关类型的值。
    // READ: <https://zh.cppreference.com/w/cpp/language/union>
    union TypePun {
        ColorEnum e;
        Color c;
    };

    TypePun pun;
    pun.c = c; 
    return pun.e; 
}


int main(int argc, char **argv) {
    ASSERT(convert_by_pun(Color::Red) == COLOR_RED, "Type punning conversion");
    ASSERT(convert_by_pun(Color::Green) == COLOR_GREEN, "Type punning conversion");
    ASSERT(convert_by_pun(Color::Yellow) == COLOR_YELLOW, "Type punning conversion");
    ASSERT(convert_by_pun(Color::Blue) == COLOR_BLUE, "Type punning conversion");
    return 0;
}
