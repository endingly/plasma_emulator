#include <cuda_runtime.h>

#include <stdexcept>

#include "odeint.hpp"

namespace gds::parallel::odeint::internal {

__global__ void odeint_kernel(double* result, double* x, double* y, double n) {
  int tidx = blockIdx.x * blockDim.x + threadIdx.x;
  if (tidx < n) {
    double x0 = x[tidx];
    double x1 = x[tidx + 1];
    double y0 = y[tidx];
    double y1 = y[tidx + 1];

    result[tidx] = (y0 + y1) * (x1 - x0) * 0.5;
  }
}

};  // namespace gds::parallel::odeint::internal

namespace gds::parallel::odeint {

double integrate(std::vector<double>& x, std::vector<double>& y) {
  // check input size
  if (x.size() != y.size()) {
    throw std::invalid_argument("x and y must have the same size");
  }

  // allocate device memory
  double* x_dev;
  double* y_dev;
  cudaMalloc(&x_dev, x.size() * sizeof(double));
  cudaMalloc(&y_dev, y.size() * sizeof(double));

  // copy data to device
  cudaMemcpy(x_dev, x.data(), x.size() * sizeof(double), cudaMemcpyHostToDevice);
  cudaMemcpy(y_dev, y.data(), y.size() * sizeof(double), cudaMemcpyHostToDevice);

  // config thread block and grid size
  int n          = x.size();
  int block_size = 256;
  int grid_size  = (n + block_size - 1) / block_size;

  // allocate device memory for result
  double* result_dev;
  cudaMalloc(&result_dev, n * sizeof(double));

  // call kernel
  gds::parallel::odeint::internal::odeint_kernel<<<grid_size, block_size>>>(result_dev, x_dev, y_dev, n);

  // copy result back to host
  double* result = (double*)malloc(n * sizeof(double));
  cudaMemcpy(result, result_dev, n * sizeof(double), cudaMemcpyDeviceToHost);

  // epilogue
  double integral = 0.0;
  for (int i = 0; i < n - 1; i++) {
    integral += result[i];
  }

  // free device memory
  cudaFree(x_dev);
  cudaFree(y_dev);
  cudaFree(result_dev);
  delete[] result;

  return integral;
}

}  // namespace gds::parallel::odeint
