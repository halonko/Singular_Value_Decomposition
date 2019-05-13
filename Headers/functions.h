#ifndef CURS_WORK_FUNCTIONS_H
#define CURS_WORK_FUNCTIONS_H

#include <vector>
#include <random>
#include "my_matrix.h"

my_matrix normaldisribution(size_t n);

my_matrix RandomUnitVector(int n);

my_matrix svd_for_1_d(my_matrix &matrix, double epsilon = 1e-10);

void SVD(my_matrix &matrix, std::vector<double> &owner_double, std::vector<my_matrix> &owner_u, std::vector<my_matrix> &owner_v,
         size_t k = 0, const double epsilon = 1e-10);

void run_SVD_on_matrix(std::vector<std::vector<double>> &array, size_t k, const double epsilon);

#endif //CURS_WORK_FUNCTIONS_H
