find_package(units CONFIG REQUIRED)
find_package(Eigen3 CONFIG REQUIRED)
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.c")
add_library(core ${SOURCES})
target_include_directories(core PUBLIC include)
target_link_libraries(core PUBLIC units::units Eigen3::Eigen common)
if(INTEL_MKL_BACKEND)
    target_compile_definitions(core PRIVATE INTEL_MKL_BACKEND)
    target_compile_options(
        core PRIVATE -DMKL_ILP64 -m64 -I${MKL_ROOT}/include
    )
    target_link_options(
        core PRIVATE
        -m64 -L${MKL_ROOT}/lib
        -lmkl_scalapack_ilp64
        -Wl,--no-as-needed
        -lmkl_intel_ilp64
        -lmkl_gnu_thread
        -lmkl_core
        -lmkl_blacs_openmpi_ilp64
        -lgomp
        -lpthread
        -lm
        -ldl
    )
endif()

if(BUILD_TESTS)
    add_subdirectory(test)
endif()