#include "../exercise.h"
#include <array>
#include <cstring>

int main(int argc, char **argv) {
    {
        std::array<int, 5> arr{{1, 2, 3, 4, 5}};
        ASSERT(arr.size() == 5, "Fill in the correct value."); // 数组的大小是其元素的数量
        ASSERT(sizeof(arr) == sizeof(int) * 5, "Fill in the correct value."); // 数组的 sizeof 等于其元素类型大小乘以元素数量
        int ans[]{1, 2, 3, 4, 5};
        ASSERT(std::memcmp(arr.data(), ans, sizeof(ans)) == 0, "Fill in the correct values."); // 使用 data() 获取数组的原始数据
    }
    {
        std::array<double, 8> arr;
        ASSERT(arr.size() == 8, "Fill in the correct value."); // 默认构造的数组，元素未初始化
        ASSERT(sizeof(arr) == sizeof(double) * 8, "Fill in the correct value."); // 同上
    }
    {
        std::array<char, 21> arr{"Hello, InfiniTensor!"};
        ASSERT(arr.size() == 21, "Fill in the correct value."); // 包括字符串结束符 '\0'
        ASSERT(sizeof(arr) == sizeof(char) * 21, "Fill in the correct value."); // 同上
        ASSERT(std::strcmp(arr.data(), "Hello, InfiniTensor!") == 0, "Fill in the correct value."); // 使用 data() 获取数组的原始数据
    }
    return 0;
}
