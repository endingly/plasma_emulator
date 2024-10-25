#include <gtest/gtest.h>
#include <omp.h>

#include <Eigen/Eigen>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <numbers>

using namespace std::chrono;

inline double f(double x) { return 1.0 / (1.0 + x * x); }

TEST(OdeintTest, test_cpu_serial) {
  constexpr double   start_x   = 0.0;
  constexpr double   end_x     = 1.0;
  constexpr uint64_t num_steps = 4194304;
  constexpr double   step_size = (end_x - start_x) / num_steps;

  double result = 0.0;

  // 计算 CPU 串行版本的时间
  auto starttime = system_clock::now();

  for (uint64_t i = 0; i < num_steps - 1; i++) {
    double head = start_x + i * step_size;
    double tail = start_x + (i + 1) * step_size;
    result += (f(tail) + f(head)) * step_size * 0.5;
  }

  auto endtime  = system_clock::now();
  auto duration = duration_cast<microseconds>(endtime - starttime).count();

  double golden_result = std::numbers::pi;

  std::cout << "CPU acaculated in serial result: " << 4 * result << std::endl;
  std::cout << "CPU golden result: " << golden_result << std::endl;
  std::cout << "CPU time: " << duration << " microseconds" << std::endl;
}

TEST(OdeintTest, test_cpu_openmp) {
  constexpr double   start_x   = 0.0;
  constexpr double   end_x     = 1.0;
  constexpr uint64_t num_steps = 4194304;
  constexpr double   step_size = (end_x - start_x) / num_steps;

  double result = 0.0;

  // 计算 CPU 串行版本的时间
  auto starttime = system_clock::now();

#pragma omp parallel for reduction(+ : result)
  for (uint64_t i = 0; i < num_steps - 1; i++) {
    double head = start_x + i * step_size;
    double tail = start_x + (i + 1) * step_size;
    result += (f(tail) + f(head)) * step_size * 0.5;
  }

  auto endtime  = system_clock::now();
  auto duration = duration_cast<microseconds>(endtime - starttime).count();

  double golden_result = std::numbers::pi;

  std::cout << "CPU[openmp] acaculated in serial result: " << 4 * result << std::endl;
  std::cout << "CPU[openmp] golden result: " << golden_result << std::endl;
  std::cout << "CPU[openmp] time: " << duration << " microseconds" << std::endl;
  std::cout << std::sqrt(num_steps) << std::endl;
}
