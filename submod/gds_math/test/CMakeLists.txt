find_package(GTest CONFIG REQUIRED)
file(GLOB_RECURSE GDS_MATH_TEST_SOURCES *.cpp)
add_executable(gds_math_test ${GDS_MATH_TEST_SOURCES})
target_link_libraries(gds_math_test PRIVATE GTest::gtest GTest::gtest_main gds_math)