#ifndef CURS_WORK_MATRIX_H
#define CURS_WORK_MATRIX_H


#include <vector>
#include <iostream>
#include <thread>
#include <math.h>

class Matrix {
public:
    Matrix(size_t m, size_t n, int number_of_threads);

    Matrix transpose();

    void set_data(size_t index_row, size_t index_column, double data);

    double get_data(size_t index_row, size_t index_column);

    void print();

    Matrix multiply_by(Matrix matrix1);

    double dot_product(const Matrix &matrix1);

    void norm();

    size_t row_size();

    size_t column_size();

private:
    int number_of_threads;
    size_t number_of_rows;
    size_t number_of_columns;
    std::vector<std::vector<double>> matrix;
};


#endif //CURS_WORK_MATRIX_H
