// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#ifndef CURS_WORK_MATRIX_H
#define CURS_WORK_MATRIX_H


#include <vector>
#include <thread>
#include <math.h>
#include <iostream>

class Matrix {
public:
    Matrix(size_t m, size_t n);

    Matrix(const Matrix &matrix);

    Matrix(const std::vector<std::vector<double>> &origin);

    Matrix transpose();

    void set_data(size_t index_row, size_t index_column, double data);

    const double get_data(size_t index_row, size_t index_column) const;

    void print() const;

    Matrix multiply_by(const Matrix &matrix1, double number = 1.0);

    double dot_product(const Matrix &matrix1);

    void norm();

    const size_t row_size() const;

    const size_t column_size() const;

    const size_t size() const;

    double lenght(size_t column = 0);

    void subtract(const Matrix &matrix1);

    std::vector<std::vector<double>> to_vector();

private:
    size_t number_of_rows;
    size_t number_of_columns;
    std::vector<std::vector<double>> matrix;
};


#endif //CURS_WORK_MATRIX_H
