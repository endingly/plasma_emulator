#include <gtest/gtest.h>

#include "log.hpp"
using namespace gds::common;

TEST(Log, print) {
  Logger::info("Hello, World!");
  Logger::info("Hello, World!");
  Logger::info("Hello, World!");
}

TEST(Log, print2file) {
  Logger::is_log_to_file_ = true;
  Logger::info("Hello, World!");
  Logger::info("Hello, World!");
  Logger::info("Hello, World!");
}