#include <gtest/gtest.h>

#include <chrono>
#include <iostream>
#include <numbers>

#include "odeint.hpp"

inline double f(double x) { return 4.0 / (1.0 + x * x); }

TEST(OdeintTest, Test_ompOdeint) {
  constexpr uint64_t step_num = 4194304;
  auto               r        = gds::parallel::odeint::integrate(f, 0.0, 1.0, step_num);
  EXPECT_NEAR(r, std::numbers::pi, 1e-5);
}
