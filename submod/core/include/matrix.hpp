#pragma once
#ifdef INTEL_MKL_BACKEND
#define EIGEN_USE_MKL_ALL
#endif

#include <Eigen/Dense>
#include <Eigen/Sparse>

#include "config.hpp"

namespace gds::core {

using config::x_cells, config::y_cells;

using Matrix       = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::ColMajor>;
using ESM          = Eigen::SparseMatrix<double>;
using stack_matrix = Eigen::Matrix<double, x_cells, y_cells, Eigen::ColMajor>;

template <typename T>
concept EigenMatrixLike = std::is_base_of_v<Eigen::DenseBase<T>, T>;

};  // namespace gds::core