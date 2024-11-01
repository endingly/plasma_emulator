find_package(OpenMP)
find_package(GSL REQUIRED)

file(GLOB_RECURSE GDS_MATH_SOURCES src/*.cpp)
add_library(gds_math ${GDS_MATH_SOURCES})
target_include_directories(
    gds_math
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
    INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
    INTERFACE $<INSTALL_INTERFACE:include>
)
target_link_libraries(gds_math PUBLIC OpenMP::OpenMP_CXX GSL::gsl GSL::gslcblas)

copy_header_files(${CMAKE_CURRENT_LIST_DIR}/include ${CMAKE_CURRENT_BINARY_DIR}/include/gds_math)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_subdirectory(benchmark)