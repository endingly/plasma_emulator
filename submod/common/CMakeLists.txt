find_package(fmt CONFIG REQUIRED)
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.c")
add_library(common ${SOURCES})
target_include_directories(
    common PUBLIC
    $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
target_link_libraries(common PRIVATE fmt::fmt)

if(PLASMA_DEBUG)
    target_compile_definitions(common PUBLIC PLASMA_DEBUG)
endif()

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

copy_header_files(${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_BINARY_DIR}/include/common)