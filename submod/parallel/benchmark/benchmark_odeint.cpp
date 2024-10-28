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