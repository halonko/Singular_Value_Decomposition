// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include <vector>
#include "my_matrix.h"
#include <gtest/gtest.h>

using std::vector;

my_matrix make_matrix() {
    my_matrix matrix = my_matrix(3, 2);
    matrix.set_data(0, 0, 4);
    matrix.set_data(0, 1, 11);
    matrix.set_data(2, 0, 14);
    matrix.set_data(1, 0, 8);
    matrix.set_data(1, 1, 7);
    matrix.set_data(2, 1, -2);
    return matrix;
}

TEST(BasicTests, CreationTest) {
    // must be no exceptions
    ASSERT_NO_THROW(my_matrix(5, 5));
    vector<vector<double>> vmatrix;
    vmatrix.resize(1);
    vmatrix.at(0).resize(1);
    my_matrix matrix1(vmatrix);
    const my_matrix &matrix2(matrix1);
    ASSERT_NO_THROW(make_matrix());
}

TEST(BasicTests, CheckSizeTest) {
    // must be no exceptions
    my_matrix mtrx = make_matrix();
    ASSERT_EQ(mtrx.row_size(), 2);
    ASSERT_EQ(mtrx.column_size(), 3);
    ASSERT_DOUBLE_EQ(mtrx.lenght(), 16.61324772583615);
}

TEST(BasicTests, SimpleOperationsTest) {
    // must be no exceptions
    my_matrix mtrx = make_matrix();
    ASSERT_NO_THROW(mtrx.transpose());
    ASSERT_NO_THROW(mtrx.multiply_by(mtrx, 10));
    ASSERT_DOUBLE_EQ(mtrx.dot_product(mtrx), 276);
    ASSERT_NO_THROW(mtrx.norm());
    ASSERT_NO_THROW(mtrx.subtract(mtrx));
    ASSERT_NO_THROW(mtrx.to_vector());
}

TEST(BasicTests, PrintTest) {
    // must be no exceptions
    my_matrix mtrx = make_matrix();
    std::cout << std::endl;
    ASSERT_NO_THROW(mtrx.print());
}

TEST(BasicTests, SetAndGetTest) {
    // must be no exceptions
    my_matrix mtrx = make_matrix();
    ASSERT_DOUBLE_EQ(mtrx.get_data(0, 0), 4);
    ASSERT_DOUBLE_EQ(mtrx.get_data(1, 1), 7);
    ASSERT_DOUBLE_EQ(mtrx.get_data(2, 1), -2);
    ASSERT_NO_THROW(mtrx.set_data(0, 0, 267));
    ASSERT_NO_THROW(mtrx.set_data(1, 1, 50));
    ASSERT_NO_THROW(mtrx.set_data(2, 1, -197));
    ASSERT_DOUBLE_EQ(mtrx.get_data(0, 0), 267);
    ASSERT_DOUBLE_EQ(mtrx.get_data(1, 1), 50);
    ASSERT_DOUBLE_EQ(mtrx.get_data(2, 1), -197);
    ASSERT_THROW(mtrx.get_data(100, 100), std::runtime_error);
    ASSERT_THROW(mtrx.set_data(100, 100, 439839), std::runtime_error);
}