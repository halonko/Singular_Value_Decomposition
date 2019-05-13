#include "../Headers/functions.h"
#include "time_count.h"

using std::max;
using std::min;
using std::copy;
using std::vector;
using std::random_device;
using std::default_random_engine;
using std::normal_distribution;

my_matrix normaldisribution(size_t n) {
    my_matrix one_d_array = my_matrix(n, 1);
    default_random_engine generator(random_device{}());
    normal_distribution<double> distribution(0.0, 1.0);
    for (size_t index = 0; index < n; index++) {
        one_d_array.set_data(index, 0, distribution(generator));
    }
    return one_d_array;
}

my_matrix RandomUnitVector(int n) {
    my_matrix unnormalized = normaldisribution(n);
    unnormalized.norm();
    return unnormalized;
}


my_matrix svd_for_1_d(my_matrix &matrix, const double epsilon) {
    size_t n = matrix.column_size();
    size_t m = matrix.row_size();

    my_matrix x = RandomUnitVector(min(n, m));

    my_matrix lastV = my_matrix(min(n, m), 1);
    my_matrix currentV = x;
    my_matrix result = my_matrix(min(n, m), min(n, m));
    auto start_time = get_current_time_fenced();
    if (n > m) {
        result = matrix.transpose().multiply_by(matrix);
    } else {
        result = matrix.multiply_by(matrix.transpose());
    }
    auto end_time = get_current_time_fenced();
    std::cout << to_us(end_time - start_time) << std::endl;
    while (true) {
        lastV = currentV;
        currentV = result.multiply_by(lastV);
        currentV.norm();
        if (fabs(currentV.dot_product(lastV)) > 1 - epsilon) {
            return currentV;
        }
    }
}

void SVD(my_matrix &matrix, vector<double> &owner_double, vector<my_matrix> &owner_u, vector<my_matrix> &owner_v, size_t k,
         const double epsilon) {
    size_t n = matrix.column_size();
    size_t m = matrix.row_size();
    if (k == 0) {
        k = min(n, m);
    }
    for (size_t i = 0; i < k; ++i) {
        my_matrix copied = my_matrix(matrix);
        for (size_t j = 0; j < i && j < owner_double.size(); ++j) {
            copied.subtract(owner_u[j].multiply_by(owner_v[j].transpose(), owner_double[j]));
        }
        double sigma;
        if (n > m) {
            my_matrix v = svd_for_1_d(copied, epsilon);
            my_matrix u = matrix.multiply_by(v);
            sigma = u.lenght();
            u.norm();
            owner_u.push_back(u);
            owner_v.push_back(v);
        } else {
            my_matrix u = svd_for_1_d(copied);
            my_matrix v = matrix.transpose().multiply_by(u);
            sigma = v.lenght();
            v.norm();
            owner_u.push_back(u);
            owner_v.push_back(v);
        }

        owner_double.push_back(sigma);
    }
}

void run_SVD_on_matrix(vector<vector<double>> &array, size_t k, const double epsilon) {
    my_matrix matrix(array);
    vector<double> owner_double;
    vector<my_matrix> owner_u;
    vector<my_matrix> owner_v;
    SVD(matrix, owner_double, owner_u, owner_v, k, epsilon);
    my_matrix sigma(owner_double.size(), owner_double.size());
    my_matrix u(owner_double.size(), matrix.column_size());
    my_matrix v(owner_double.size(), matrix.row_size());
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