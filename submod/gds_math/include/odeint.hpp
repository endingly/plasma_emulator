#pragma once
#include <vector>

namespace gds::math::odeint {

using one_dim_func_gsl = double (*)(double, void*);

double integrate(one_dim_func_gsl f, double start_x, double end_x);

}  // namespace gds::math::odeint
