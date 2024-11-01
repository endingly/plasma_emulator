#include <gtest/gtest.h>

#include <iostream>
#include <string>

#include "core/matrix.hpp"
#include "core/matrix_helper.hpp"

TEST(MatrixHelperTest, Test_init_tridiagonal_matrix) {
  std::array<double, 3> diag = {1, 2, 3};
  auto matrix = gds::core::MatrixHelper::init_tridiagonal_matrix<10>(diag);
  std::cout << matrix << std::endl;
}

TEST(MatrixHelperTest, Test_init_fiveiagonal_matrix) {
  std::array<double, 5> diag = {3, 1, 2, 3, 4};
  auto matrix = gds::core::MatrixHelper::init_fivediagonal_matrices<25>(diag);
  std::cout << matrix << std::endl;
}

TEST(MatrixHelperTest, Test_write_load_matrix_to_file) {
  gds::core::Matrix m = gds::core::Matrix::Random(10, 10);
  auto r = gds::core::MatrixHelper::write_matrix_to_CSV(m, "test.csv");
  EXPECT_TRUE(r);
  auto lr = gds::core::MatrixHelper::load_matrix_from_CSV("test.csv");
  using gds::core::operator==;
  EXPECT_TRUE(m == lr);
}