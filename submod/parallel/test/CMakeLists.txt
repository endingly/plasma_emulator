find_package(GTest CONFIG REQUIRED)
file(GLOB_RECURSE PARALLEL_TEST_SOURCES *.cpp)
add_executable(parallel_test ${PARALLEL_TEST_SOURCES})
target_link_libraries(parallel_test PRIVATE GTest::gtest GTest::gtest_main parallel)
set_target_properties(
    parallel_test PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)