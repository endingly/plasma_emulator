#include <gtest/gtest.h>

#include <chrono>
#include <gds_math/odeint.hpp>
#include <iostream>
#include <numbers>

static double f_gsl(double x, void* params) {
  return 4.0 / (1.0 + x * x);
}

TEST(OdeintTest, Test_cudaOdeint) {
  // init data
  auto data = gds::math::odeint::integrate(f_gsl, 0.0, 1.0);
  EXPECT_NEAR(data, std::numbers::pi, 1e-7);
}
