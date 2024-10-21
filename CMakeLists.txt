cmake_minimum_required(VERSION 3.25)

project(plasma_emulator VERSION 0.0.1 LANGUAGES CXX C)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

option(BUILD_TESTS "Build tests" ON)
option(INTEL_MKL_BACKEND "Use Intel MKL backend" OFF)
option(CUDA_BACKEND "Enable CUDA backend" OFF)
option(CICD_ENABLE "Enable CICD" ON)

if(CICD_ENABLE)
    enable_testing()
    add_test(
        NAME ctest_all 
        COMMAND python ${CMAKE_CURRENT_SOURCE_DIR}/scripts/run_ctest.py
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
else()
    message(STATUS "CICD_ENABLE is off, tests will not be run on CI/CD")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    option(PLASMA_DEBUG "Enable plasma debug messages, NOT FOR PRODUCTION USE" ON)
else()
    option(PLASMA_DEBUG "Enable plasma debug messages, NOT FOR PRODUCTION USE" OFF)
endif()


if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")
endif()

add_subdirectory(submod)
add_subdirectory(app)