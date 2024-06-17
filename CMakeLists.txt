cmake_minimum_required(VERSION 3.25)

project(plasma_emulator VERSION 0.0.1 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

option(BUILD_TESTS "Build tests" ON)
option(INTEL_MKL_BACKEND "Use Intel MKL backend" ON)

add_subdirectory(submod)