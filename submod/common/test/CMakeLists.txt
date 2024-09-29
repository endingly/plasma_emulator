find_package(GTest CONFIG REQUIRED)
file(GLOB_RECURSE SOURCES *.cpp)
add_executable(common_test ${SOURCES})
target_link_libraries(common_test common GTest::gtest GTest::gtest_main)

add_test(NAME common_test COMMAND common_test)