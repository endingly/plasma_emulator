enable_language(CUDA)


find_package(OpenMP)
file(GLOB_RECURSE PARALLEL_SOURCES src/*.cpp src/*.cu)

add_library(parallel ${PARALLEL_SOURCES})
target_include_directories(parallel PUBLIC include)
target_link_libraries(parallel PUBLIC OpenMP::OpenMP_CXX)

set_target_properties(
    parallel PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

if(BUILD_TESTS)
    find_package(GTest CONFIG REQUIRED)
    file(GLOB_RECURSE PARALLEL_TEST_SOURCES test/*.cpp)
    add_executable(parallel_test ${PARALLEL_TEST_SOURCES})
    target_link_libraries(parallel_test PRIVATE GTest::gtest GTest::gtest_main parallel)
    set_target_properties(
        parallel_test PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
    )
endif()
