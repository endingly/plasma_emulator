#include "odeint.hpp"

#include <gsl/gsl_integration.h>
#include <omp.h>

#include <cstdint>

double gds::math::odeint::integrate(one_dim_func_gsl f, double start_x,
                                    double end_x) {
  gsl_integration_workspace* workspace = gsl_integration_workspace_alloc(1000);

  gsl_function F;
  F.function = f;
  F.params   = nullptr;

  double result, abserr;
  double epsabs = 1e-7, epsrel = 1e-7;

  int status = gsl_integration_qags(&F, start_x, end_x, epsabs, epsrel, 1000,
                                    workspace, &result, &abserr);

  gsl_integration_workspace_free(workspace);
  return result;
}
