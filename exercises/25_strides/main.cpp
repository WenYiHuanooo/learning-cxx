#include "../exercise.h"
#include <vector>

using udim = unsigned int;

std::vector<udim> strides(std::vector<udim> const &shape) {
    std::vector<udim> strides(shape.size());
    strides.back() = 1; // 最后一个维度的步长总是 1

    // 从后向前计算步长
    for (auto it = shape.rbegin() + 1; it != shape.rend(); ++it) {
        *it = *(it - 1) * *it;
    }

    return strides;
}

int main(int argc, char **argv) {
    ASSERT((strides({2, 3, 4}) == std::vector<udim>{12, 4, 1}), "Make this assertion pass.");
    ASSERT((strides({3, 4, 5}) == std::vector<udim>{20, 5, 1}), "Make this assertion pass.");
    ASSERT((strides({1, 3, 224, 224}) == std::vector<udim>{150528, 50176, 224, 1}), "Make this assertion pass.");
    ASSERT((strides({7, 1, 1, 1, 5}) == std::vector<udim>{5, 5, 5, 5, 1}), "Make this assertion pass.");
    return 0;
}
