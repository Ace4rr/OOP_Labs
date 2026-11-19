#include "lab01/matrix_ops.hpp"

#include <gtest/gtest.h>

namespace lab01 {
namespace {

TEST(MatrixCreateTest, AllocatesMatrixAndRows) {
    constexpr std::size_t kRows{2};
    constexpr std::size_t kCols{3};

    int** matrix = matrix_create(kRows, kCols);

    ASSERT_NE(matrix, nullptr);
    EXPECT_NE(matrix[0], nullptr);
    EXPECT_NE(matrix[1], nullptr);

    matrix_delete(matrix, kRows);
    matrix = nullptr;
}

TEST(MatrixCreateTest, InitializesZeroElements) {
    constexpr std::size_t kRows{2};
    constexpr std::size_t kCols{2};

    int** matrix = matrix_create(kRows, kCols);

    ASSERT_NE(matrix, nullptr);
    for (std::size_t i = 0; i < kRows; ++i) {
        ASSERT_NE(matrix[i], nullptr);
        for (std::size_t j = 0; j < kCols; ++j) {
            EXPECT_EQ(matrix[i][j], 0);
        }
    }

    matrix_delete(matrix, kRows);
    matrix = nullptr;
}

TEST(MatrixCreateTest, ZeroDimensionsReturnsNullptr) {
    EXPECT_EQ(matrix_create(0, 0), nullptr);
    EXPECT_EQ(matrix_create(0, 3), nullptr);
    EXPECT_EQ(matrix_create(3, 0), nullptr);
}

TEST(MatrixDeleteTest, NullptrOk) {
    EXPECT_NO_THROW(matrix_delete(nullptr, 0));
    EXPECT_NO_THROW(matrix_delete(nullptr, 3));
}

TEST(MatrixFillTest, FillsMatrix) {
    constexpr std::size_t kRows{2};
    constexpr std::size_t kCols{3};
    const int value = -7;

    int** matrix = matrix_create(kRows, kCols);
    ASSERT_NE(matrix, nullptr);

    matrix_fill(matrix, kRows, kCols, value);

    for (std::size_t i = 0; i < kRows; ++i) {
        for (std::size_t j = 0; j < kCols; ++j) {
            EXPECT_EQ(matrix[i][j], value);
        }
    }

    matrix_delete(matrix, kRows);
    matrix = nullptr;
}

TEST(MatrixFillTest, ReplacesPreviousValues) {
    constexpr std::size_t kRows{2};
    constexpr std::size_t kCols{2};

    int** matrix = matrix_create(kRows, kCols);
    ASSERT_NE(matrix, nullptr);

    matrix_fill(matrix, kRows, kCols, 1);
    matrix_fill(matrix, kRows, kCols, 2);

    for (std::size_t i = 0; i < kRows; ++i) {
        for (std::size_t j = 0; j < kCols; ++j) {
            EXPECT_EQ(matrix[i][j], 2);
        }
    }

    matrix_delete(matrix, kRows);
    matrix = nullptr;
}

TEST(MatrixRowMaxTest, SampleFromManual) {
    constexpr std::size_t kRows{2};
    constexpr std::size_t kCols{3};

    int** matrix = matrix_create(kRows, kCols);
    ASSERT_NE(matrix, nullptr);

    matrix[0][0] = 3;
    matrix[0][1] = 1;
    matrix[0][2] = 4;

    matrix[1][0] = 5;
    matrix[1][1] = 2;
    matrix[1][2] = 0;

    int* r_max = matrix_row_max(matrix, kRows, kCols);
    ASSERT_NE(r_max, nullptr);

    EXPECT_EQ(r_max[0], 4);
    EXPECT_EQ(r_max[1], 5);

    delete[] r_max;
    matrix_delete(matrix, kRows);
}

TEST(MatrixRowMaxTest, NegativeNumbers) {
    constexpr std::size_t kRows{2};
    constexpr std::size_t kCols{2};

    int** matrix = matrix_create(kRows, kCols);
    ASSERT_NE(matrix, nullptr);

    matrix[0][0] = -10;
    matrix[0][1] = -5;
    matrix[1][0] = -20;
    matrix[1][1] = -1;

    int* r_max = matrix_row_max(matrix, kRows, kCols);
    ASSERT_NE(r_max, nullptr);

    EXPECT_EQ(r_max[0], -5);
    EXPECT_EQ(r_max[1], -1);

    delete[] r_max;
    matrix_delete(matrix, kRows);
}

TEST(MatrixRowMaxTest, SingleRowAndSingleCol) {
    int** row_m = matrix_create(1, 3);
    ASSERT_NE(row_m, nullptr);
    row_m[0][0] = 10;
    row_m[0][1] = 50;
    row_m[0][2] = 20;

    int* r_max = matrix_row_max(row_m, 1, 3);
    ASSERT_NE(r_max, nullptr);
    EXPECT_EQ(r_max[0], 50);
    delete[] r_max;
    matrix_delete(row_m, 1);

    int** col_m = matrix_create(3, 1);
    ASSERT_NE(col_m, nullptr);
    col_m[0][0] = 10;
    col_m[1][0] = 50;
    col_m[2][0] = 20;

    int* r_max2 = matrix_row_max(col_m, 3, 1);
    ASSERT_NE(r_max2, nullptr);
    EXPECT_EQ(r_max2[0], 10);
    EXPECT_EQ(r_max2[1], 50);
    EXPECT_EQ(r_max2[2], 20);
    delete[] r_max2;
    matrix_delete(col_m, 3);
}

TEST(MatrixColMinTest, SampleFromManual) {
    constexpr std::size_t kRows{2};
    constexpr std::size_t kCols{3};

    int** matrix = matrix_create(kRows, kCols);
    ASSERT_NE(matrix, nullptr);

    matrix[0][0] = 3;
    matrix[0][1] = 1;
    matrix[0][2] = 4;

    matrix[1][0] = 5;
    matrix[1][1] = 2;
    matrix[1][2] = 0;

    int* c_min = matrix_col_min(matrix, kRows, kCols);
    ASSERT_NE(c_min, nullptr);

    EXPECT_EQ(c_min[0], 3);
    EXPECT_EQ(c_min[1], 1);
    EXPECT_EQ(c_min[2], 0);

    delete[] c_min;
    matrix_delete(matrix, kRows);
}

TEST(MatrixColMinTest, NegativeNumbers) {
    constexpr std::size_t kRows{2};
    constexpr std::size_t kCols{2};

    int** matrix = matrix_create(kRows, kCols);
    ASSERT_NE(matrix, nullptr);

    matrix[0][0] = -10;
    matrix[0][1] = -5;
    matrix[1][0] = -20;
    matrix[1][1] = -1;

    int* c_min = matrix_col_min(matrix, kRows, kCols);
    ASSERT_NE(c_min, nullptr);

    EXPECT_EQ(c_min[0], -20);
    EXPECT_EQ(c_min[1], -5);

    delete[] c_min;
    matrix_delete(matrix, kRows);
}

TEST(MatrixColMinTest, SingleRowAndSingleCol) {
    int** row_m = matrix_create(1, 3);
    ASSERT_NE(row_m, nullptr);
    row_m[0][0] = 10;
    row_m[0][1] = 50;
    row_m[0][2] = 20;

    int* c_min = matrix_col_min(row_m, 1, 3);
    ASSERT_NE(c_min, nullptr);
    EXPECT_EQ(c_min[0], 10);
    EXPECT_EQ(c_min[1], 50);
    EXPECT_EQ(c_min[2], 20);
    delete[] c_min;
    matrix_delete(row_m, 1);

    int** col_m = matrix_create(3, 1);
    ASSERT_NE(col_m, nullptr);
    col_m[0][0] = 10;
    col_m[1][0] = 50;
    col_m[2][0] = 20;

    int* c_min2 = matrix_col_min(col_m, 3, 1);
    ASSERT_NE(c_min2, nullptr);
    EXPECT_EQ(c_min2[0], 10);
    delete[] c_min2;
    matrix_delete(col_m, 3);
}

TEST(MatrixOpsTest_Fail, NullptrReturnsNullptr) {
    EXPECT_EQ(matrix_row_max(nullptr, 0, 0), nullptr);
    EXPECT_EQ(matrix_row_max(nullptr, 2, 2), nullptr);
    EXPECT_EQ(matrix_col_min(nullptr, 0, 0), nullptr);
    EXPECT_EQ(matrix_col_min(nullptr, 2, 2), nullptr);
}

}  // namespace
}  // namespace lab01
