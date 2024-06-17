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
concept EigenMatrix = std::is_same_v<T, Matrix> || std::is_same_v<T, ESM> || std::is_same_v<T, stack_matrix> ||
                      std::is_same_v<T, Eigen::VectorXd>;

};  // namespace gds::core