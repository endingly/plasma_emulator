# copy header files from src_dir to dest_dir, not including subdirectories
function(copy_header_files src_dir dest_dir)
    # find all header files in src_dir
    file(GLOB_RECURSE header_files
        "${src_dir}/*.h"
        "${src_dir}/*.hpp"
    )

    # cretate destination directory if it doesn't exist
    if(NOT EXISTS ${dest_dir})
        file(MAKE_DIRECTORY ${dest_dir})
    endif()

    # copy all header files to destination directory
    foreach(header_file ${header_files})
        # get header file name without path and extension
        get_filename_component(header_name ${header_file} NAME)
        # copy header file to destination directory
        file(COPY ${header_file} DESTINATION ${dest_dir})
    endforeach()
endfunction()