#include "../exercise.h"

// READ: 运算符 <https://zh.cppreference.com/w/cpp/language/expressions#.E8.BF.90.E7.AE.97.E7.AC.A6>

int main(int argc, char **argv) {
    // 定义一个整型变量 x 并初始化，例如初始化为 5
    int x = 5;

    // 使用 std::cout 输出加法运算的结果
    std::cout << x << " + " << x << " = " << x + x << std::endl;
    return 0;
}
