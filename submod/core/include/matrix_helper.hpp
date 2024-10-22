#pragma once
#include <fstream>

#include "matrix.hpp"
#include "common/type_limits.hpp"

namespace gds::core {
class MatrixHelper {
 public:
  /// @brief writes a matrix to a CSV file
  /// @tparam T sparse/dense matrix/vector type
  /// @param matrix specifies the matrix to be written to the CSV file
  /// @param file_name the name of the CSV file to be written to
  /// @return true if the matrix was successfully written to the CSV file, false otherwise
  template <gds::core::EigenMatrix T>
  bool write_matrix_to_CSV(const T& matrix, const std::string& file_name) {
    std::ofstream file;
    file.open(file_name, std::ios::out | std::ios::binary);
    if (!file.is_open()) {
      return false;
    }
    file << matrix << std::endl;
    file.close();
    return true;
  }

  /// @brief initializes a tridiagonal matrix with the given diagonal, subdiagonal, and superdiagonal elements
  /// @param n size of the matrix
  /// @param elements diagonal, subdiagonal, and superdiagonal elements of the matrix
  /// @return the initialized tridiagonal sparse matrix
  template <size_t n>
  static gds::core::ESM init_tridiagonal_matrix(std::array<double, 3> elements) {
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
};
}  // namespace gds::core
