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

TEST(OdeintTest, Test_cudaOdeint) {
  // init data
  constexpr uint64_t step_num  = 4194304;
  constexpr double   start_x   = 0.0;
  constexpr double   end_x     = 1.0;
  constexpr double   step_size = (end_x - start_x) / step_num;

  std::vector<double> x(step_num);
  std::vector<double> y(step_num);
  for (int i = 0; i < step_num; i++) {
    x[i] = start_x + i * step_size;
    y[i] = f(x[i]);
  }
  // integrate
  auto result = gds::parallel::odeint::integrate(x, y);
  EXPECT_NEAR(result, std::numbers::pi, 1e-5);
}
