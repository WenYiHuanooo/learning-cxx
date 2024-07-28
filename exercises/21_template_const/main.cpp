#include "../exercise.h"
#include <cstring>

template<unsigned int N, class T>
struct Tensor {
    unsigned int shape[N];
    T *data;

    Tensor(unsigned int const shape_[N]) {
        for (unsigned int i = 0; i < N; ++i) {
            shape[i] = shape_[i];
        }
        unsigned int size = 1;
        for (unsigned int i = 0; i < N; ++i) {
            size *= shape[i];
        }
        data = new T[size];
        std::memset(data, 0, size * sizeof(T));
    }
    ~Tensor() {
        delete[] data;
    }

    // 禁止复制和移动
    Tensor(Tensor const &) = delete;
    Tensor(Tensor &&) noexcept = delete;

    T &operator[](unsigned int const indices[N]) {
        return data[data_index(indices)];
    }
    T const &operator[](unsigned int const indices[N]) const {
        return data[data_index(indices)];
    }

private:
    unsigned int data_index(unsigned int const indices[N]) const {
        unsigned int index = 0;
        unsigned int stride = 1;
        for (int i = N - 1; i >= 0; --i) {
            ASSERT(indices[i] < shape[i]);
            index += indices[i] * stride;
            stride *= shape[i];
        }
        return index;
    }
};
