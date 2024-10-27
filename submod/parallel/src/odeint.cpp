#include "odeint.hpp"

#include <omp.h>

#include <cstdint>

double gds::parallel::odeint::integrate(one_dim_func f, double start_x, double end_x, double step_num) {
  uint64_t num_steps = step_num;
  double   step_size = (end_x - start_x) / num_steps;

  double result = 0.0;

#pragma omp parallel for reduction(+ : result)
  for (int64_t i = 0; i < num_steps; i++) {
    double head = start_x + i * step_size;
    double tail = start_x + (i + 1) * step_size;
    result += (f(tail) + f(head)) * step_size * 0.5;
  }

  return result;
}