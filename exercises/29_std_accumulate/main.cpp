#include "../exercise.h"
#include <numeric>
#include <iostream>

int main(int argc, char **argv) {
    using DataType = float;
    int shape[]{1, 3, 224, 224};
    
    // 使用 std::accumulate 计算张量元素的总数
    auto total_elements = std::accumulate(shape, shape + 4, 1, std::multiplies<int>());
    
    // 计算占用的字节数，float 类型占用 4 个字节
    int size = total_elements * sizeof(DataType);
    
    // 断言检查结果是否正确
    ASSERT(size == 602112, "4x1x3x224x224 = 602112");
    
    std::cout << "Size in bytes: " << size << std::endl;
    return 0;
}
