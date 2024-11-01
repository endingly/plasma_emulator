find_package(units CONFIG REQUIRED)
find_package(Eigen3 CONFIG REQUIRED)
find_path(RAPIDCSV_INCLUDE_DIRS "rapidcsv.h")
find_package(OpenMP REQUIRED)
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.c")
add_library(core STATIC ${SOURCES})
target_include_directories(
    core
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
    PUBLIC ${RAPIDCSV_INCLUDE_DIRS}
    INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
    INTERFACE $<INSTALL_INTERFACE:include>
)
target_link_libraries(core PUBLIC units::units Eigen3::Eigen common OpenMP::OpenMP_CXX)

if(INTEL_MKL_BACKEND)
    message(STATUS "Using Intel MKL backend")
    set(MKL_INTERFACE "lp64")
    set(ENABLE_BLACS ON)
    find_package(MKL REQUIRED CONFIG)
    target_compile_definitions(core PUBLIC INTEL_MKL_BACKEND)
    target_link_libraries(core PUBLIC MKL::MKL MKL::MKL_BLACS MKL::MKL_SCALAPACK)
endif()

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

copy_header_files(${CMAKE_CURRENT_LIST_DIR}/include ${CMAKE_CURRENT_BINARY_DIR}/include/core)