file(GLOB_RECURSE APP_SOURCES "src/*.cpp")
add_executable(plasma_emulator ${APP_SOURCES})
target_link_libraries(plasma_emulator core chempars)