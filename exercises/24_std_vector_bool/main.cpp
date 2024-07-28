#include "../exercise.h"
#include <vector>

int main(int argc, char **argv) {
    // 正确调用构造函数，初始化大小为100，每个元素为true
    std::vector<bool> vec(100, true);
    ASSERT(vec[0], "Make this assertion pass."); // 断言vec[0]为true
    ASSERT(vec[99], "Make this assertion pass."); // 断言vec[99]为true
    ASSERT(vec.size() == 100, "Make this assertion pass."); // 断言vec的大小为100

    // sizeof(vec)不包括vec所包含的bool值的内存大小，而是vector<bool>对象本身的内存大小
    // 这个值与实现有关，但通常远小于100
    ASSERT(sizeof(vec) < 100, "Fill in the correct value.");

    {
        vec[20] = false; // 将vec[20]设置为false
        ASSERT(!vec[20], "Fill in `vec[20]` or `!vec[20]`.");
    }

    {
        vec.push_back(false); // 在vec末尾添加一个false
        ASSERT(vec.size() == 101, "Fill in the correct value."); // 断言vec的大小变为101
        ASSERT(!vec[100], "Fill in `vec[100]` or `!vec[100]`."); // 断言新添加的元素为false
    }

    {
        auto ref = vec[30]; // 获取vec[30]的引用
        ASSERT(ref, "Fill in `ref` or `!ref`"); // 断言ref为true（因为之前没有修改过）
        ref = false; // 将vec[30]设置为false
        ASSERT(!ref, "Fill in `ref` or `!ref`"); // 断言ref为false
        ASSERT(!vec[30], "Fill in `vec[30]` or `!vec[30]`."); // 断言vec[30]为false
    }

    return 0;
}
