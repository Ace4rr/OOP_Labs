#pragma once
#include <cstddef>

namespace lab01{
    int* MatrixRowMax(const int* const* m, std::size_t rows, std::size_t cols);
    int* MatrixColMin(const int* const* m, std::size_t rows, std::size_t cols);
}