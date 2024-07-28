#include "../exercise.h"
#include <string>

int main(int argc, char **argv) {
    using namespace std::string_literals;
    auto hello = "Hello"s;
    auto world = "world";
    
    // 使用 decltype 获取 hello 和 world 的类型
    ASSERT((std::is_same_v<decltype(hello), std::string>), "Fill in the missing type.");
    ASSERT((std::is_same_v<decltype(world), const char*>), "Fill in the missing type.");

    // 将 hello 和 world 连接成一个字符串
    ASSERT(hello + ", " + world + '!' == "Hello, world!", "Fill in the missing string.");

    return 0;
}
