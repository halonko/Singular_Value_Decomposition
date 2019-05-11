#include "../Headers/functions.h"

using std::vector;
using std::min;
using std::copy;
using std::max;
using std::random_device;
using std::default_random_engine;
using std::normal_distribution;

Matrix normaldisribution(size_t n) {
    Matrix one_d_array = Matrix(n, 1, 4);
    default_random_engine generator(random_device{}());
    normal_distribution<double> distribution(0.0, 1.0);
    for (size_t index = 0; index < n; index++) {
        one_d_array.set_data(index, 0, distribution(generator));
    }
    return one_d_array;
}

Matrix RandomUnitVector(int n) {
    Matrix unnormalized = normaldisribution(n);
    unnormalized.norm();
    return unnormalized;
}


Matrix svd_for_1_d(Matrix &matrix, const double epsilon) {
    size_t n = matrix.column_size();
    size_t m = matrix.row_size();
    Matrix x = RandomUnitVector(min(n, m));
    Matrix lastV = Matrix(min(n, m), 1, 4);
    Matrix currentV = x;
    Matrix result = Matrix(min(n, m), min(n, m), 4);
    if (n > m) {
        result = matrix.transpose().multiply_by(matrix);
    } else {
        result = matrix.multiply_by(matrix.transpose());
    }
    while (true) {
        lastV = currentV;
        currentV = result.multiply_by(lastV);
        currentV.norm();
        if (fabs(lastV.dot_product(currentV.transpose())) > 1 - epsilon) {
            return currentV;
        }
    }
}

