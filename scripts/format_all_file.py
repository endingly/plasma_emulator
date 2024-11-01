import os
import subprocess
import threading

# define the root directory and clang-format path
root_dir = "./submod/"
clang_format_path = "C:/Users/m00980/.vscode/extensions/ms-vscode.cpptools-1.22.10-win32-x64/LLVM/bin/clang-format"

# define the file types to be formatted
file_types = [".c", ".h", ".cpp", ".hpp"]


# define the function to run clang-format on a list of files
def run_clang_format(file_list):
    for file_path in file_list:
        print(f"formatting file：{file_path}")
        subprocess.call([clang_format_path, "-i", file_path, "--style=file"])
        print(f"formatted file：{file_path}")
    # os.system("clang-format -i %s -style=File" % (" ".join(file_list)))


# recursively traverse the root directory and collect all files with the specified file types
def traverse_and_collect(root_dir):
    file_list = []
    for root, dirs, files in os.walk(root_dir):
        for file in files:
            file_path = os.path.join(root, file)
            if file_path.endswith(tuple(file_types)):
                file_list.append(file_path)
                if len(file_list) == 10:
                    thread = threading.Thread(
                        target=run_clang_format, args=(file_list,)
                    )
                    thread.start()
                    file_list = []
    if file_list:
        thread = threading.Thread(target=run_clang_format, args=(file_list,))
        thread.start()


# create a new thread to traverse the root directory and collect all files
traverse_thread = threading.Thread(target=traverse_and_collect, args=(root_dir,))
traverse_thread.start()

# wait for the traverse thread to finish
traverse_thread.join()