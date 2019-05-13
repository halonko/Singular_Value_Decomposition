// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#ifndef CURS_WORK_FUNCTIONS_H
#define CURS_WORK_FUNCTIONS_H

#include <vector>
#include "my_matrix.h"

my_matrix normaldisribution(size_t n);

my_matrix RandomUnitVector(size_t n);

my_matrix svd_for_1_d(my_matrix &matrix, double epsilon = 1e-10);

void SVD(my_matrix &matrix, std::vector<double> &owner_double, std::vector<my_matrix> &owner_u,
         std::vector<my_matrix> &owner_v,
         size_t k = 0, double epsilon = 1e-10);

void run_SVD_on_matrix(std::vector<std::vector<double>> &array, size_t k = 0, double epsilon = 1e-10);

#endif //CURS_WORK_FUNCTIONS_H
