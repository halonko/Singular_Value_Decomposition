// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include <random>
#include "functions.h"
#include "time_count.h"

using std::max;
using std::min;
using std::copy;
using std::vector;
using std::random_device;
using std::default_random_engine;
using std::normal_distribution;

Matrix normaldisribution(size_t n) {
    Matrix one_d_array = Matrix(n, 1);
    default_random_engine generator(random_device{}());
    normal_distribution<double> distribution(0.0, 1.0);
    for (size_t index = 0; index < n; ++index) {
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

    Matrix lastV = Matrix(min(n, m), 1);
    Matrix currentV = x;
    Matrix result = Matrix(min(n, m), min(n, m));
    if (n > m) {
        result = matrix.transpose().multiply_by(matrix);
    } else {
        result = matrix.multiply_by(matrix.transpose());
    }
    while (true) {
        lastV = currentV;
        currentV = result.multiply_by(lastV);
        currentV.norm();
        if (fabs(currentV.dot_product(lastV)) > 1 - epsilon) {
            return currentV;
        }
    }
}

void SVD(Matrix &matrix, vector<double> &owner_double, vector<Matrix> &owner_u, vector<Matrix> &owner_v, size_t k,
         const double epsilon) {
    size_t n = matrix.column_size();
    size_t m = matrix.row_size();
    if (k == 0) {
        k = min(n, m);
    }
    for (size_t i = 0; i < k; ++i) {
        Matrix copied = Matrix(matrix);
        for (size_t j = 0; j < i && j < owner_double.size(); ++j) {
            copied.subtract(owner_u[j].multiply_by(owner_v[j].transpose(), owner_double[j]));
        }
        double sigma;
        if (n > m) {
            Matrix v = svd_for_1_d(copied, epsilon);
            Matrix u = matrix.multiply_by(v);
            sigma = u.lenght();
            u.norm();
            owner_u.push_back(u);
            owner_v.push_back(v);
        } else {
            Matrix u = svd_for_1_d(copied);
            Matrix v = matrix.transpose().multiply_by(u);
            sigma = v.lenght();
            v.norm();
            owner_u.push_back(u);
            owner_v.push_back(v);
        }

        owner_double.push_back(sigma);
    }
}

void run_SVD_on_matrix(vector<vector<double>> &array, size_t k, const double epsilon) {
    Matrix matrix(array);
    vector<double> owner_double;
    vector<Matrix> owner_u;
    vector<Matrix> owner_v;
    SVD(matrix, owner_double, owner_u, owner_v, k, epsilon);
    Matrix sigma(owner_double.size(), owner_double.size());
    Matrix u(owner_double.size(), matrix.column_size());
    Matrix v(owner_double.size(), matrix.row_size());
    for (size_t i = 0; i < owner_double.size(); ++i) {
        sigma.set_data(i, i, owner_double.at(i));
    }
    for (size_t i = 0; i < owner_u.size(); ++i) {
        for (size_t j = 0; j < owner_u.at(0).column_size(); ++j) {
            u.set_data(i, j, owner_u.at(i).get_data(j, 0));
        }
    }
    for (size_t i = 0; i < owner_v.size(); ++i) {
        for (size_t j = 0; j < owner_v.at(0).column_size(); ++j) {
            v.set_data(i, j, owner_v.at(i).get_data(j, 0));
        }
    }
    matrix = u.transpose().multiply_by(sigma).multiply_by(v);
    array = matrix.to_vector();
}