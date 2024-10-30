#include "odeint.hpp"

#include <gsl/gsl_integration.h>
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

double gds::parallel::odeint::integrate(one_dim_func_gsl f, double start_x, double end_x) {
  gsl_integration_workspace *workspace = gsl_integration_workspace_alloc(1000);

  gsl_function F;
  F.function = f;
  F.params   = nullptr;

  double result, abserr;
  double epsabs = 1e-7, epsrel = 1e-7;

  int status = gsl_integration_qags(&F, start_x, end_x, epsabs, epsrel, 1000, workspace, &result, &abserr);

  gsl_integration_workspace_free(workspace);
  return result;
}
