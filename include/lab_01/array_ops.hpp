#pragma once 
#include <cstddef>

namespace lab01{
    int** MatrixCreate(std::size_t rows, std::size_t cols);
    void MatrixDelete(int** m, std::size_t rows);
    void MatrixFill(int** m,std::site_t rows,std::size_t cols, int value);  
}

