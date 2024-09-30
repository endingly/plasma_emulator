find_package(GTest CONFIG REQUIRED)
file(GLOB_RECURSE SOURCES *.cpp)
add_executable(chempars_test ${SOURCES})
target_link_libraries(chempars_test chempars GTest::gtest GTest::gtest_main)