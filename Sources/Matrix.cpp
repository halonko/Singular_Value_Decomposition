#include "Matrix.h"

using std::vector;
using std::to_string;
using std::cout;
using std::endl;
using std::string;
using std::ceil;
using std::max;
using std::min;
using std::sqrt;

Matrix::Matrix(size_t m, size_t n, int new_number_of_threads) {
    matrix.reserve(m);
    number_of_rows = m;
    number_of_columns = n;
    number_of_threads = new_number_of_threads;
    max_matrix_value = 0;
    for (size_t i = 0; i < number_of_rows; i++) {
        matrix.emplace_back();
        for (size_t j = 0; j < number_of_columns; j++) {
            matrix.at(i).push_back(double{});
        }
    }
}

Matrix Matrix::transpose() {
    auto new_matrix = Matrix(number_of_columns, number_of_rows, number_of_threads);

    for (size_t i = 0; i < number_of_columns; i++) {
        for (size_t j = 0; j < number_of_rows; j++) {
            new_matrix.set_data(i, j, matrix.at(j).at(i));
        }
    }
    return new_matrix;
}

void Matrix::print() {
    cout << "Matrix with " << number_of_rows << " rows and " << number_of_columns << " columns: " << endl << endl;
    for (size_t i = 0; i < number_of_rows; i++) {
        for (size_t j = 0; j < number_of_columns; j++) {
            cout << std::setw(static_cast<int>(this->max_matrix_value)) << std::left;
            cout << matrix.at(i).at(j);
        }
        cout << endl << endl;
    }
}

void Matrix::set_data(size_t index_row, size_t index_column, double data) {
    size_t current_length = to_string(matrix.at(index_row).at(index_column)).size();
    if (this->max_matrix_value <= current_length) {
        this->max_matrix_value = current_length;
    }
    matrix.at(index_row).at(index_column) = data;
}

double Matrix::get_data(size_t index_row, size_t index_column) {
    return matrix.at(index_row).at(index_column);
}

Matrix Matrix::multiply_by(Matrix matrix1) {
    auto new_matrix = Matrix(number_of_rows, matrix1.number_of_columns, number_of_threads);
    for(size_t i= 0; i < number_of_rows; i++){
        for(size_t j = 0; j < matrix1.number_of_columns; j++){
            double current{0};
            for(size_t z = 0; z < matrix1.number_of_rows; z++){
                current += matrix.at(i).at(z) * matrix1.get_data(z, j);
            }
            new_matrix.set_data(i, j, current);
        }
    }
    return new_matrix;
}

double Matrix::dot_product(const Matrix& matrix1) {
    if(matrix1.number_of_rows != 1 || number_of_columns != 1){
        throw std::range_error("Must be vector");
    }
    auto new_matrix = multiply_by(matrix1);
    double result{0};
    for(size_t i = 0; i < new_matrix.number_of_rows; i++){
        result += new_matrix.get_data(i, 0);
    }
    return result;
}

void Matrix::norm() {
    double length;
    for(size_t column_index = 0; column_index < number_of_columns; column_index++){
        length = 0;
        for(size_t row_index = 0; row_index < number_of_rows; row_index++){
            length += matrix.at(row_index).at(column_index) * matrix.at(row_index).at(column_index);
        }
        length = sqrt(length);
        for(size_t row_index = 0; row_index < number_of_rows; row_index++){
            matrix.at(row_index).at(column_index) /= length;
        }
    }
}
