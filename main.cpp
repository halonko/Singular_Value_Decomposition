#include <iostream>
#include "Matrix.h"

int main() {
    Matrix matrix = Matrix(2, 3, 4);
    matrix.set_data(0, 0, 4);
    matrix.set_data(0, 1, 11);
    matrix.set_data(0, 2, 14);
    matrix.set_data(1, 0, 8);
    matrix.set_data(1, 1, 7);
    matrix.set_data(1, 2, -2);

    auto transpose_matrix = matrix.transpose();
    matrix.print();
    transpose_matrix.print();
    auto multiplication_matrix = matrix.multiply_by(transpose_matrix);
    multiplication_matrix.print();
    return 0;
}