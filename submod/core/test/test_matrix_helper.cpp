#include <gtest/gtest.h>

#include <iostream>

#include "core/matrix_helper.hpp"

TEST(MatrixHelperTest, Test_init_tridiagonal_matrix) {
  std::array<double, 3> diag   = {1, 2, 3};
  auto                  matrix = gds::core::MatrixHelper::init_tridiagonal_matrix<10>(diag);
  std::cout << matrix << std::endl;
}

TEST(MatrixHelperTest, Test_init_fiveiagonal_matrix) {
  std::array<double, 5> diag   = {3, 1, 2, 3, 4};
  auto                  matrix = gds::core::MatrixHelper::init_fivediagonal_matrices<25>(diag);
  std::cout << matrix << std::endl;
}

TEST(MatrixHelperTest, Test_write_matrix_to_file) {
  auto m = gds::core::Matrix::Random(5, 5);
  auto r = gds::core::MatrixHelper::write_matrix_to_CSV(m, "test.csv");
  EXPECT_TRUE(r);
}

TEST(MatrixHelperTest, Test_load_matrix_from_file) {
  auto m = gds::core::MatrixHelper::load_matrix_from_CSV("test.csv");
  std::cout << m << std::endl;
}