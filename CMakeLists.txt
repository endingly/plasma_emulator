cmake_minimum_required(VERSION 3.25)

project(chempars VERSION 0.0.1 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

option(BUILD_TESTS "Build tests" ON)

find_package(fmt CONFIG REQUIRED)
find_package(units CONFIG REQUIRED)
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.c")
add_library(chempars ${SOURCES})
target_include_directories(chempars PUBLIC include)
target_link_libraries(chempars PUBLIC fmt::fmt units::units)
if(BUILD_TESTS)
    add_subdirectory(test)
endif()