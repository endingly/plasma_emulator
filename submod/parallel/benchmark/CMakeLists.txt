find_package(benchmark CONFIG REQUIRED)
file(GLOB_RECURSE PARALLEL_BENCHMARK_SOURCES *.cpp)
add_executable(parallel_benchmark ${PARALLEL_BENCHMARK_SOURCES})
target_link_libraries(parallel_benchmark PRIVATE benchmark::benchmark benchmark::benchmark_main parallel)