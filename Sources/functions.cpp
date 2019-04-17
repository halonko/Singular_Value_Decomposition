#include "../Headers/functions.h"

using std::vector;
using std::min;
using std::max;

vector<vector<double >> transpose_A(const vector<vector<double>> &A) {
    return A;
}

vector<vector<double>> not_transpose_A(const vector<vector<double >> &A) {
    return A;
}

vector<vector<double >> multiply_matrix(const vector<vector<double >> &A, const vector<vector<double>> &B) {
    vector<vector<double>> result;
    result.reserve(max(A.size(), A[0].size()));
    for(auto & row : result){
        row.reserve(max(A.size(), A[0].size()));
    }
}

double random_number() {
    return 1;
}

vector<double > RandomUnitVector(int n) {
    vector<double > unnormalized = {};
    vector<double > normalized = {};
    size_t norm = unnormalized.size();
    return normalized;
}


vector<double> svd_for_1_d(const vector<vector<double>> &matrix, const double epsilon = 1e-10) {
    size_t n = matrix.size();
    size_t m = matrix[0].size();
    vector<double> x = RandomUnitVector(min(n, m));
    vector<double> lastV;
    vector<double> currentV = x;
    double scalar_product;
    return currentV;

}

