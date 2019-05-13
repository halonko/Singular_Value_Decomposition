#ifndef CURS_WORK_FUNCTIONS_H
#define CURS_WORK_FUNCTIONS_H

#include <vector>
#include <random>
#include "Matrix.h"

Matrix normaldisribution(size_t n);

Matrix RandomUnitVector(int n);

Matrix svd_for_1_d(Matrix &matrix, double epsilon = 1e-10);

void SVD(Matrix &matrix, std::vector<double> &owner_double, std::vector<Matrix> &owner_u, std::vector<Matrix> &owner_v,
         size_t k = 0, const double epsilon = 1e-10);

#endif //CURS_WORK_FUNCTIONS_H
