#include <gtest/gtest.h>

#include "common/log.hpp"
using namespace gds::common;

TEST(Log, print) {
  Logger::info("Hello, World!");
  Logger::info("Hello, World!");
  Logger::info("Hello, World!");
  Logger::debug("Debug message");
}

TEST(Log, print2file) {
  Logger::is_log_to_file_ = true;
  Logger::info("Hello, World!");
  Logger::info("Hello, World!");
  Logger::info("Hello, World!");
  Logger::debug("Debug message");
}