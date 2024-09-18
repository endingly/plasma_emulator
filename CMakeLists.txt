cmake_minimum_required(VERSION 3.25)

project(plasma_emulator VERSION 0.0.1 LANGUAGES CXX C)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

option(BUILD_TESTS "Build tests" ON)
option(INTEL_MKL_BACKEND "Use Intel MKL backend" OFF)
option(CUDA_BACKEND "Enable CUDA backend" OFF)
option(PLASMA_DEBUG "Enable plasma debug messages, NOT FOR PRODUCTION USE" ON)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")
endif()

add_subdirectory(submod)