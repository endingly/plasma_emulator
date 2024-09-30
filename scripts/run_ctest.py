# -*- coding: utf-8 -*-
import subprocess
import os
import sys

def run_binary_test(top_path, cmakeprest_name, submod_name) -> bool:
    # 调用 C++ 二进制测试程序
    path_name = f"{top_path}/out/build/{cmakeprest_name}/submod/{submod_name}/test/{submod_name}_test"
    print(f"Running binary test: {path_name}")
    result = subprocess.run(args=[path_name],shell=True,check=True,capture_output=True)
    # 检查返回码以确定测试是否通过
    return result.returncode == 0

# main function def
if __name__ == '__main__':
    top_path = os.getcwd().replace("\\", "/")
    cmakeprest_name = "mingw_x64_windows_debug"

    R0 = run_binary_test(top_path, cmakeprest_name, "common")
    R0 &= run_binary_test(top_path, cmakeprest_name, "chempars")
    R0 &=run_binary_test(top_path, cmakeprest_name, "core")

    sys.exit(R0)