add_subdirectory(chempars)
add_subdirectory(common)
add_subdirectory(core)

if(CUDA_BACKEND)
    add_subdirectory(parallel)
endif()