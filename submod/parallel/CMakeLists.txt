enable_language(CUDA)

find_package(NvidiaCutlass CONFIG REQUIRED)
file(GLOB_RECURSE PARALLEL_SOURCES src/*.cpp src/*.cu)

add_library(parallel ${PARALLEL_SOURCES})
target_include_directories(parallel PUBLIC include)
target_link_libraries(parallel PRIVATE nvidia::cutlass::cutlass)

if(BUILD_TESTS)
    file(GLOB_RECURSE PARALLEL_TEST_SOURCES test/*.cpp)
    add_executable(parallel_test ${PARALLEL_TEST_SOURCES})
    target_include_directories(parallel_test PUBLIC include)
    target_link_libraries(parallel_test PRIVATE parallel)
endif()
