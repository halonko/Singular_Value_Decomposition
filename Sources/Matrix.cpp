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

Matrix::Matrix(size_t m, size_t n) {
    matrix.reserve(m);
    number_of_rows = m;
    number_of_columns = n;
    number_of_threads = std::thread::hardware_concurrency();;
    for (size_t i = 0; i < number_of_rows; i++) {
        matrix.emplace_back();
        for (size_t j = 0; j < number_of_columns; j++) {
            matrix.at(i).push_back(double{});
        }
    }
}

Matrix Matrix::transpose() {
    auto new_matrix = Matrix(number_of_columns, number_of_rows);

    for (size_t i = 0; i < number_of_columns; i++) {
        for (size_t j = 0; j < number_of_rows; j++) {
            new_matrix.set_data(i, j, matrix.at(j).at(i));
        }
    }
    return new_matrix;
}

void Matrix::print() const {
    size_t max_lenght = 0;
    size_t current_lenght = 0;
    for (size_t i = 0; i < number_of_rows; i++) {
        for (size_t j = 0; j < number_of_columns; j++) {
            current_lenght = to_string(matrix.at(i).at(j)).size();
            if (max_lenght <= current_lenght) {
                max_lenght = current_lenght;
            }
        }
    }

    size_t empty_space;
    for (size_t i = 0; i < number_of_rows; i++) {
        for (size_t j = 0; j < number_of_columns; j++) {
            empty_space = (max_lenght - to_string(matrix.at(i).at(j)).size()) / 2;
            string to_print(empty_space, ' ');
            string to_print_left(max_lenght - empty_space - to_string(matrix.at(i).at(j)).size(), ' ');
            string empty_field(max_lenght, ' ');
            cout << to_print_left << matrix.at(i).at(j) << to_print << empty_field;
        }
        cout << endl << endl;
    }
}

void Matrix::set_data(size_t index_row, size_t index_column, double data) {
    matrix.at(index_row).at(index_column) = data;
}

const double Matrix::get_data(size_t index_row, size_t index_column) const {
    return matrix.at(index_row).at(index_column);
}

Matrix Matrix::multiply_by(const Matrix &matrix1, double number) {
    Matrix new_matrix = Matrix(number_of_rows, matrix1.number_of_columns);
    for (size_t i = 0; i < number_of_rows; i++) {
        for (size_t j = 0; j < matrix1.number_of_columns; j++) {
            double current{0};
            for (size_t z = 0; z < matrix1.number_of_rows; z++) {
                current += matrix.at(i).at(z) * matrix1.get_data(z, j) * number;
            }
            new_matrix.set_data(i, j, current);
        }
    }
    return new_matrix;
}

double Matrix::dot_product(const Matrix &matrix1) {
    double result{0.0};
    for (int i = 0; i < number_of_rows; i++) {
        result += get_data(i, 0) * matrix1.get_data(i, 0);
    }
    return result;
}

void Matrix::norm() {
    double len;
    for (size_t column_index = 0; column_index < number_of_columns; column_index++) {
        len = lenght(column_index);
        for (size_t row_index = 0; row_index < number_of_rows; row_index++) {
            matrix.at(row_index).at(column_index) /= len;
        }
    }
}

const size_t Matrix::row_size() const {
    return number_of_columns;
}

const size_t Matrix::column_size() const {
    return number_of_rows;
}

Matrix::Matrix(const Matrix &copy_matrix) {
    matrix.reserve(copy_matrix.size());
    number_of_rows = copy_matrix.column_size();
    number_of_columns = copy_matrix.row_size();
    number_of_threads = std::thread::hardware_concurrency();
    for (size_t i = 0; i < number_of_rows; i++) {
        matrix.emplace_back();
        for (size_t j = 0; j < number_of_columns; j++) {
            matrix.at(i).push_back(copy_matrix.get_data(i, j));
        }
    }
}

const size_t Matrix::size() const {
    return matrix.size();
}

double Matrix::lenght(size_t column) {
    double len = 0;
    for (size_t row_index = 0; row_index < number_of_rows; ++row_index) {
        len += matrix.at(row_index).at(column) * matrix.at(row_index).at(column);
    }
    len = sqrt(len);
    return len;
}

void Matrix::subtract(const Matrix &matrix1) {
    for (size_t i = 0; i < number_of_rows; ++i) {
        for (size_t j = 0; j < number_of_columns; ++j) {
            matrix.at(i).at(j) -= matrix1.get_data(i, j);
        }
    }
}
