find_package(fmt CONFIG REQUIRED)
find_package(units CONFIG REQUIRED)
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.c")
add_library(chempars ${SOURCES})
target_include_directories(
    chempars
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
    INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
    INTERFACE $<INSTALL_INTERFACE:include>
)
target_link_libraries(chempars PUBLIC fmt::fmt units::units core)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

copy_header_files(${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_BINARY_DIR}/include/chempars)