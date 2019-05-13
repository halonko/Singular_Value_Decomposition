#ifndef CURS_WORK_MY_MATRIX_H
#define CURS_WORK_MY_MATRIX_H


#include <vector>
#include <thread>
#include <math.h>
#include <iostream>
#include <Eigen/Dense>

class my_matrix {
public:
    my_matrix(size_t m, size_t n);

    my_matrix(const my_matrix &matrix);

    my_matrix(const std::vector<std::vector<double>>& origin);

    my_matrix transpose();

    void set_data(size_t index_row, size_t index_column, double data);

    const double get_data(size_t index_row, size_t index_column) const;

    void print() const;

    my_matrix multiply_by(const my_matrix& matrix1, double number = 1.0);

    double dot_product(const my_matrix& matrix1);

    void norm();

    const size_t row_size() const;

    const size_t column_size() const;

    const size_t size() const;

    double lenght(size_t column = 0);

    void subtract(const my_matrix &matrix1);

    std::vector<std::vector<double>> to_vector();

private:
    size_t number_of_rows;
    size_t number_of_columns;
    Eigen::Matrix2d matrix;
};


#endif //CURS_WORK_MY_MATRIX_H
