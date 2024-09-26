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

TEST(UtilsTest, Split_string) {
  std::string str    = "e + Ar^+ -> Ar^*";
  auto        result = gds::common::split(str, "->");
  EXPECT_EQ(result.value()[0], "e+Ar^+");
  EXPECT_EQ(result.value()[1], "Ar^*");

  auto result2 = gds::common::split(result.value()[0], "+");
  EXPECT_EQ(result2.value()[0], "e");
  EXPECT_EQ(result2.value()[1], "Ar^+");
}