#include "lab01/matrix_ops.hpp"

#include <iostream>

namespace lab01 {
int** matrix_create(std::size_t rows, std::size_t cols) {
    if (rows == 0 || cols == 0) {
        return nullptr;
    }

    int** matrix = new int*[rows]{};
    std::size_t rows_created = 0;

    try {
        for (std::size_t i = 0; i < rows; ++i) {
            matrix[i] = new int[cols]{};
            rows_created++;
        }
    } catch (...) {
        for (std::size_t i = 0; i < rows_created; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
        throw;
    }

    return matrix;
}

void matrix_delete(int** m, std::size_t rows) {
    if (m == nullptr) {
        return;
    }

    for (std::size_t i = 0; i < rows; ++i) {
        delete[] m[i];
    }

    delete[] m;
}

void matrix_fill(int** m, std::size_t rows, std::size_t cols, int value) {
    if (m == nullptr) {
        return;
    }

    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < cols; ++j) {
            m[i][j] = value;
        }
    }
}

void matrix_print(const int* const* m, std::size_t rows, std::size_t cols) {
    if (m == nullptr || rows == 0 || cols == 0) {
        std::cout << "(empty)" << std::endl;
        return;
    }

    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < cols; ++j) {
            if (j > 0) {
                std::cout << ' ';
            }
            std::cout << m[i][j];
        }
        std::cout << std::endl;
    }
}

int* matrix_row_max(const int* const* m, std::size_t rows, std::size_t cols) {
    if (m == nullptr || rows == 0 || cols == 0) {
        return nullptr;
    }

    int* result = new int[rows];
    for (std::size_t i = 0; i < rows; ++i) {
        int max_val = m[i][0];
        for (std::size_t j = 1; j < cols; ++j) {
            if (m[i][j] > max_val) {
                max_val = m[i][j];
            }
        }
        result[i] = max_val;
    }

    return result;
}

int* matrix_col_min(const int* const* m, std::size_t rows, std::size_t cols) {
    if (m == nullptr || rows == 0 || cols == 0) {
        return nullptr;
    }

    int* result = new int[cols];
    for (std::size_t j = 0; j < cols; ++j) {
        int min_val = m[0][j];
        for (std::size_t i = 1; i < rows; ++i) {
            if (m[i][j] < min_val) {
                min_val = m[i][j];
            }
        }
        result[j] = min_val;
    }

    return result;
}
}  // namespace lab01
