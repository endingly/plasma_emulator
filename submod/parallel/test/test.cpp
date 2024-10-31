#include <gtest/gtest.h>
#include <numbers>
#include "odeint.hpp"

static double f_gsl(double x, void* params) {
  return 4.0 / (1.0 + x * x);
}

TEST(OdeintTest, Test_cudaOdeint) {
  // init data
  auto data = gds::parallel::odeint::integrate(f_gsl, 0.0, 1.0);
  EXPECT_NEAR(data, std::numbers::pi, 1e-7);
}
