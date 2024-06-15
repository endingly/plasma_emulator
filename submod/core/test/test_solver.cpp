#include <gtest/gtest.h>

#include "matrix_helper.hpp"

TEST(SolverTest, TestSolver) {
  // build problem  Ax = b
  std::array<double, 3> elements = {10, 2, 3};
  auto                  A        = gds::core::matrix_helper::init_tridiagonal_matrix(20, elements);

  // matrix b
  Eigen::VectorXd b(20);
  b << 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20;

  // solve Ax = b
  Eigen::SimplicialLDLT<Eigen::SparseMatrix<double>> solver;
  solver.compute(A);
  Eigen::VectorXd x = solver.solve(b);

  // check solution
  std::cout << "x = " << x.transpose() << std::endl;
}

TEST(SolverTest, TestSolver_fivediagonal) {
  // build problem  Ax = b
  // A
  std::array<double, 5> elements = {10, 2, 3, 4, 5};
  auto                  A        = gds::core::matrix_helper::init_fivediagonal_matrices<80 * 80>(elements);

  // matrix b
  Eigen::VectorXd b = Eigen::VectorXd::Random(80 * 80);

  // solve Ax = b
  Eigen::SimplicialLDLT<Eigen::SparseMatrix<double>> solver;
  solver.compute(A);
  Eigen::VectorXd x = solver.solve(b);

  // check solution
  std::cout << "x length = " << x.size() << std::endl;
  std::cout << "x(0:9) = " << x.topRows(10).transpose() << std::endl;
}