#include <gtest/gtest.h>

#include "common/type_limits.hpp"

template <size_t N>
  requires gds::common::SquareRootNumber<N>
void test_limits() {
  std::cout << "Testing limits for " << N << std::endl;
}

TEST(TypeLimitsTest, TestLimits) {
  test_limits<1>();
  test_limits<4>();
}