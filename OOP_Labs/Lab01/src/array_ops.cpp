#include "lab01/matrix\_ops.hpp"

namespace lab_01{
    int MatrixCreate(std::size_t cols, std::size_t rows){
        if (rows==0 || cols==0){
            return nullptr;
        }
        int** m=new int*[rows];
        for (std::size_t i=0;i<rows;++i){
            m[i]=new int[cols]{};
        }
        return m;
    }

    void MatrixDelete(int** m, std::size_t rows){
        if (m==nullptr){
            return;
        }
        for (std::size_t i=0;i<rows;++i){
            delete[] m[i];
        }
        delete[] m;
    }

    void MatrixFill(int** m, std::size_t rows, std::size_t cols, int value){
        if (m==nullptr){
            return;
        }
        for (std::size_t i=0;i<rows;++i){
            if (m[i]==nullptr){
                continue;
            }
            for (std::size_t j=0;j<cols;++j){
                m[i][j]=value;
            }
        }
    }
}