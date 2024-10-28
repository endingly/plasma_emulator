#include <benchmark/benchmark.h>

#include "odeint.hpp"

inline double f(double x) { return 4.0 / (1.0 + x * x); }

static void odeint_pi(benchmark::State& state) {
  constexpr uint64_t step_num = 4194304;
  for (auto _ : state) {
    auto r = gds::parallel::odeint::integrate(f, 0.0, 1.0, step_num);
  }
}
BENCHMARK(odeint_pi)->Unit(benchmark::kMicrosecond);

static void odeint_pi_cuda(benchmark::State& state) {
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

  for (auto _ : state) {
    gds::parallel::odeint::integrate(x, y);
  }
}
BENCHMARK(odeint_pi_cuda)->Unit(benchmark::kMicrosecond);