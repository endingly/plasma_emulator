#pragma once
#include <fstream>
#include <optional>

#include "matrix.hpp"

namespace gds::common {

/// @brief 将矩阵写入 csv 文件
/// @tparam T 密集矩阵或者稀疏矩阵
/// @param matrix 将要写入的矩阵
/// @param file_name 文件名
/// @return 是否成功
template <EigenMatrix T>
bool Write_Matrix_To_CSV(const T& matrix, const std::string& file_name) {
  std::ofstream file;
  file.open(file_name, std::ios::out | std::ios::binary);
  if (!file.is_open()) {
    return false;
  }
  file << matrix << std::endl;
  file.close();
  return true;
}

/// @brief 从字符串中定位某一子串
/// @param str 指定要搜索的字符串
/// @param substr 指定要搜索的子串
/// @return `->` 符号的位置
int find_sign(std::string_view str, std::string_view substr);

/// @brief 从字符串中定位某一子串
/// @param begin 指向开始位置的迭代器
/// @param end 指向结束位置的迭代器
/// @param substr 指定要搜索的子串
/// @return
int find_sign(const std::string::iterator& begin,
              const std::string::iterator& end, const std::string& substr);

/// @brief 拆分字符串，内部存在拷贝开销
/// @param str 需要拆分的字符串
/// @param delim 指定拆分依据
/// @return 返回拆分结果的视图
std::optional<std::vector<std::string>> split(const std::string_view& str,
                                              const std::string_view& delim);

/// @brief 去除字符串中的空格
/// @param str 需要去除空格的字符串
/// @return 返回去除空格后的字符串
std::optional<std::string_view> remove_space(std::string_view str);

}  // namespace gds::common