#include <benchmark/benchmark.h>

#include <chrono>

#include "odeint.hpp"

inline double f(double x) { return 4.0 / (1.0 + x * x); }

static void odeint_pi(benchmark::State& state) {
  constexpr uint64_t step_num = 4194304;
  for (auto _ : state) {
    auto r = gds::parallel::odeint::integrate(f, 0.0, 1.0, step_num);
  }
}
BENCHMARK(odeint_pi)->Unit(benchmark::kMicrosecond)->Iterations(500)->MinWarmUpTime(10);

inline double f_gsl(double x, void* params) { return 4.0 / (1.0 + x * x); }
static void   odeint_pi_gsl(benchmark::State& state) {
  for (auto _ : state) {
    auto r = gds::parallel::odeint::integrate(f_gsl, 0.0, 1.0);
  }
}
BENCHMARK(odeint_pi_gsl)->Unit(benchmark::kMicrosecond)->Iterations(500)->MinWarmUpTime(10);