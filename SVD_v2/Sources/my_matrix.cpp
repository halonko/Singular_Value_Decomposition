// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include <thread>
#include <math.h>
#include <iostream>
#include "my_matrix.h"

using std::max;
using std::min;
using std::ceil;
using std::cout;
using std::sqrt;
using std::endl;
using std::string;
using std::vector;
using std::to_string;
using Eigen::MatrixXd;
using Eigen::VectorXd;

my_matrix::my_matrix(size_t m, size_t n) {
    number_of_rows = m;
    number_of_columns = n;
    matrix.resize(number_of_rows, number_of_columns);
    for (size_t i = 0; i < number_of_rows; ++i) {
        for (size_t j = 0; j < number_of_columns; ++j) {
            matrix(i, j) = double{0.0};
        }
    }
}

my_matrix my_matrix::transpose() {
    auto new_matrix = my_matrix(number_of_columns, number_of_rows);
    new_matrix.matrix = matrix.transpose();
    return new_matrix;
}

void my_matrix::print() const {
    cout << matrix << endl;
}

void my_matrix::set_data(size_t index_row, size_t index_column, double data) {
    if(index_row >= number_of_rows || index_column >= number_of_columns)
        throw std::range_error("Too big index!");
    matrix(index_row, index_column) = data;
}

const double my_matrix::get_data(size_t index_row, size_t index_column) const {
    if (index_row >= number_of_rows || index_column >= number_of_columns)
        throw std::range_error("Too big index!");
    return matrix(index_row, index_column);
}

my_matrix my_matrix::multiply_by(const my_matrix &matrix1, double number) {
    MatrixXd result_matrix = matrix * matrix1.matrix;
    my_matrix result_my_matrix(result_matrix.rows(), result_matrix.cols());
    result_my_matrix.matrix = result_matrix * number;
    return result_my_matrix;
}

double my_matrix::dot_product(const my_matrix &matrix1) {
    return matrix.col(0).dot(matrix1.matrix.col(0));
}

void my_matrix::norm() {
    matrix /= matrix.norm();
}

const size_t my_matrix::row_size() const {
    return matrix.cols();
}

const size_t my_matrix::column_size() const {
    return matrix.rows();
}

my_matrix::my_matrix(const my_matrix &copy_matrix) {
    number_of_rows = copy_matrix.column_size();
    number_of_columns = copy_matrix.row_size();
    matrix.resize(number_of_rows, number_of_columns);
    for (size_t i = 0; i < number_of_rows; ++i) {
        for (size_t j = 0; j < number_of_columns; ++j) {
            matrix(i, j) = copy_matrix.matrix(i, j);
        }
    }
}

my_matrix::my_matrix(const vector<vector<double>> &origin) {
    number_of_rows = origin.size();
    number_of_columns = origin.at(0).size();
    matrix.resize(number_of_rows, number_of_columns);
    for (size_t i = 0; i < number_of_rows; ++i) {
        for (size_t j = 0; j < number_of_columns; ++j) {
            matrix(i, j) = origin.at(i).at(j);
        }
    }
}

double my_matrix::lenght(size_t column) {
    double len = 0;
    for (size_t row_index = 0; row_index < number_of_rows; ++row_index) {
        len += matrix(row_index, column) * matrix(row_index, column);
    }
    len = sqrt(len);
    return len;
}

void my_matrix::subtract(const my_matrix &matrix1) {
    matrix -= matrix1.matrix;
}

vector<vector<double>> my_matrix::to_vector() {
    vector<vector<double>> origin;
    origin.resize(matrix.rows());
    for (size_t i = 0; i < number_of_rows; ++i) {
        origin.at(i).resize(matrix.cols());
        for (size_t j = 0; j < number_of_columns; ++j) {
            origin.at(i).at(j) = matrix(i, j);
        }
    }
    return origin;
}
