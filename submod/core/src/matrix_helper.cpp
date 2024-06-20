#include "matrix_helper.hpp"

#include <iostream>

namespace gds::core {

gds::core::ESM MatrixHelper::init_tridiagonal_matrix(int n, std::array<double, 3> elements) {
  // the tridiagonal matrix is a square matrix with n rows and n columns
  std::vector<Eigen::Triplet<double>> entities;
  for (int i = 0; i < n; i++) {
    entities.push_back(Eigen::Triplet<double>(i, i, elements[1]));
    if (i < n - 1) entities.push_back(Eigen::Triplet<double>(i, i + 1, elements[2]));
    if (i > 0) entities.push_back(Eigen::Triplet<double>(i, i - 1, elements[0]));
  }
  gds::core::ESM tridiagonal_matrix(n, n);
  tridiagonal_matrix.setFromTriplets(entities.begin(), entities.end());
  return tridiagonal_matrix;
}

}  // namespace gds::core