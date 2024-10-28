find_package(benchmark CONFIG REQUIRED)
file(GLOB_RECURSE PARALLEL_BENCHMARK_SOURCES *.cpp)
add_executable(parallel_benchmark ${PARALLEL_BENCHMARK_SOURCES})
target_link_libraries(parallel_benchmark PRIVATE benchmark::benchmark benchmark::benchmark_main parallel)

# include(FetchContent)
# FetchContent_Declare(
#     nvbench
#     GIT_REPOSITORY https://github.com/NVIDIA/nvbench.git
#     GIT_TAG        92286e1d4ae60e1ae66b3a5b9b75a570bbf4713d
# )
# FetchContent_MakeAvailable(nvbench)