find_package(benchmark CONFIG REQUIRED)
file(GLOB_RECURSE GDS_MATH_BENCHMARK_SOURCES *.cpp)
add_executable(gds_math_benchmark ${GDS_MATH_BENCHMARK_SOURCES})
target_link_libraries(gds_math_benchmark PRIVATE benchmark::benchmark benchmark::benchmark_main gds_math)