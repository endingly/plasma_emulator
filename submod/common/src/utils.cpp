#include "utils.hpp"

#include <algorithm>
#include <functional>
#include <stdexcept>
#include <string>

#include "log.hpp"

namespace gds::common {

int find_sign(std::string_view str, std::string_view substr) {
  auto pos = std::search(str.begin(), str.end(), std::boyer_moore_searcher(substr.begin(), substr.end()));
  if (pos == str.end()) {
    const std::string msg = "Error: cannot find `->` in the string";
    Logger::error(msg);
    throw std::logic_error(msg);
  }
  return std::distance(str.begin(), pos);
}

int find_sign(const std::string::iterator& begin, const std::string::iterator& end, const std::string& substr) {
  auto pos = std::search(begin, end, std::boyer_moore_searcher(substr.begin(), substr.end()));
  if (pos == end) {
    std::string msg = "Error: cannot find `->` in the string";
    Logger::error(msg);
    throw std::logic_error(msg);
  }
  return std::distance(begin, pos);
}

std::optional<std::vector<std::string>> split(const std::string_view& str, const std::string_view& delim) {
  if (str.empty()) {
    return std::nullopt;
  }
  std::vector<std::string> result;
  std::string::size_type   pos_begin = 0;
  std::string::size_type   pos       = str.find(delim);
  // 循环拆分字符串
  while (pos != std::string::npos) {
    if (pos != pos_begin) {
      auto substr = str.substr(pos_begin, pos - pos_begin);
      // 去除空格
      auto str_view = remove_space(substr);
      if (str_view.has_value()) {
        result.emplace_back(str_view.value());
      }
      pos_begin = pos + delim.length();
      pos       = str.find(delim, pos_begin);
    } else {
      // 需要排除掉带 `+` `-` 符号的情况
      pos_begin = pos + delim.length();
      pos       = str.find(delim, pos_begin);
    }
  }
  // 最后一个符号
  if (pos_begin != str.length()) {
    auto substr = str.substr(pos_begin, pos - pos_begin);
    // 去除空格
    auto str_view = remove_space(substr);
    if (str_view.has_value()) {
      result.emplace_back(str_view.value());
    }
  }
  return result;
}

std::optional<std::string> remove_space(std::string_view str) {
  if (str.empty()) {
    return std::nullopt;
  }

  std::string result(str);
  result.erase(std::remove(result.begin(), result.end(), ' '), result.end());
  return result;
}

};  // namespace gds::common