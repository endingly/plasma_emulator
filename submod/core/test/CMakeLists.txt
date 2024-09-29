find_package(GTest CONFIG REQUIRED)
file(GLOB_RECURSE SOURCES *.cpp)
add_executable(core_test ${SOURCES})
target_link_libraries(core_test core GTest::gtest GTest::gtest_main)

add_test(NAME core_test COMMAND core_test)