#pragma once
#include <string>

namespace gds::common {

enum class LogLevel { INFO, WARNING, ERROR, DEBUG };

class Logger {
 public:
  static inline std::string log_file_path_ = "./log/";
  static inline bool is_log_to_file_       = false;

 private:
  static void writeLog(LogLevel log_level, const std::string& log);

 public:
  static void info(const std::string& log);
  static void warning(const std::string& log);
  static void error(const std::string& log);
  static void debug(const std::string& log);
};

}  // namespace gds::common