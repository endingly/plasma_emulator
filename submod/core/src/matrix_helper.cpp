#include "matrix_helper.hpp"

#include <iostream>

#include "type_limits.hpp"

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

/// @brief initializes a fivediagonal matrix with the given elements of a row
/// @tparam n size of the matrix, assumed to be a perfect square
/// @param elements elements of a row of the matrix
/// @return the initialized fivediagonal sparse matrix
template <size_t n>
static gds::core::ESM init_fivediagonal_matrices(std::array<double, 5u> elements)
  requires(gds::common::SquareRootNumber<n>)
{
  // the fivediagonal matrices are square matrices with n rows and n columns
  // and `n` is a perfect square
  // check if n is a perfect square
  std::vector<Eigen::Triplet<double>> entities;
  for (int i = 0; i < n; i++) {
    entities.push_back(Eigen::Triplet<double>(i, i, elements[2]));
    if (i > 0) entities.push_back(Eigen::Triplet<double>(i, i - 1, elements[1]));
    if (i >= std::sqrt(n) - 1) entities.push_back(Eigen::Triplet<double>(i, i - std::sqrt(n) + 1, elements[0]));
    if (i < n - 1) entities.push_back(Eigen::Triplet<double>(i, i + 1, elements[3]));
    if (i < n - std::sqrt(n) + 1) entities.push_back(Eigen::Triplet<double>(i, i + std::sqrt(n) - 1, elements[4]));
  }
  gds::core::ESM fivediagonal_matrices(n, n);
  fivediagonal_matrices.setFromTriplets(entities.begin(), entities.end());
  return fivediagonal_matrices;
}

}  // namespace gds::core