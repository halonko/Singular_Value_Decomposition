#include "../Headers/functions.h"

using std::vector;
using std::min;
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


Matrix svd_for_1_d(const vector<vector<double>> &matrix, const double epsilon = 1e-10) {
    size_t n = matrix.size();
    size_t m = matrix[0].size();
    Matrix x = RandomUnitVector(min(n, m));
    Matrix currentV = x;
    double scalar_product;
    return currentV;

}

