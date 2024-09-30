# -*- coding: utf-8 -*-
import subprocess
import os
import sys
import platform

def run_binary_test(top_path, cmakeprest_name, submod_name) -> bool:
    path_name = ""
    if platform.system() == "Linux":
        path_name = f"{top_path}/out/build/{cmakeprest_name}/submod/{submod_name}/test/{submod_name}_test"
    elif platform.system() == "Windows":
        path_name = f"{top_path}/out/build/{cmakeprest_name}/submod/{submod_name}/test/Release/{submod_name}_test.exe"
    result = subprocess.run(args=[path_name],shell=True,check=True,capture_output=True)
    return result.returncode == 0

# main function def
if __name__ == '__main__':
    top_path = os.getcwd().replace("\\", "/")
    cmakeprest_name = ""
    if platform.system() == "Windows":
        cmakeprest_name = "MSVC_x64_release"
    elif platform.system() == "Linux":
        cmakeprest_name = "linux_gcc_x64_release"

    R0 =  run_binary_test(top_path, cmakeprest_name, "common")
    R0 &= run_binary_test(top_path, cmakeprest_name, "chempars")
    R0 &= run_binary_test(top_path, cmakeprest_name, "core")

    sys.exit(0 if R0 else 1)