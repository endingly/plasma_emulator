#pragma once
#include <vector>

namespace gds::parallel::odeint {

using one_dim_func     = double (*)(double);
using two_dim_func     = double (*)(double, double);
using three_dim_func   = double (*)(double, double, double);
using one_dim_func_gsl = double (*)(double, void*);

double integrate(std::vector<double>& x, std::vector<double>& y);
double integrate(one_dim_func f, double start_x, double end_x, double step_num);
double integrate(one_dim_func_gsl f, double start_x, double end_x);

}  // namespace gds::parallel::odeint