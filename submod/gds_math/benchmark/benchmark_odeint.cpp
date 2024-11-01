#include <benchmark/benchmark.h>

#include <chrono>

#include <gds_math/odeint.hpp>

inline double f_gsl(double x, void* params) { return 4.0 / (1.0 + x * x); }
static void   odeint_pi_gsl(benchmark::State& state) {
  for (auto _ : state) {
    auto r = gds::math::odeint::integrate(f_gsl, 0.0, 1.0);
  }
}
BENCHMARK(odeint_pi_gsl)->Unit(benchmark::kMicrosecond)->Iterations(500);