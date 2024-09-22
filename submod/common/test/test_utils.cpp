#include <gtest/gtest.h>

#include <string>

#include "utils.hpp"

TEST(UtilsTest, Find_singe) {
  std::string str     = "hello world";
  std::string pattern = "l";
  auto        result  = gds::common::find_sign(str, pattern);
  EXPECT_EQ(result, 2);
}

TEST(UtilsTest, Remove_space) {
  std::string str    = "hello world";
  auto        result = gds::common::remove_space(str);
  EXPECT_EQ(result.value(), "helloworld");
}

TEST(UtilTest, Split_string) {
  std::string str    = "hello world";
  auto        result = gds::common::split(str, " ");
  EXPECT_EQ(result.value()[0], "hello");
  EXPECT_EQ(result.value()[1], "world");
}