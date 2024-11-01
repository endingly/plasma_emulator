#include <gtest/gtest.h>

#include <iostream>

#include "core/config.hpp"
#include "core/physic_constant.hpp"
#include "core/units_extend.hpp"

TEST(UnitsTest, TestUnits) {
  std::cout << gds::physic_constant::T_e << std::endl;
  std::cout << units::reaction_rate::cubic_centimeter_per_second_t(1) << std::endl;
}

TEST(UnitsTest, TestConfig) {
  std::cout << gds::config::xmax << std::endl;
  std::cout << gds::config::ymax << std::endl;
  std::cout << gds::config::pressure << std::endl;
  std::cout << gds::config::voltage << std::endl;
}

TEST(UnitsTest, Test_Extend_To_string) {
  using units::literals::operator""_ccps;
  auto ccs = 1_ccps;
  auto s   = units::extend::to_string(ccs);
  EXPECT_EQ(s, "1e+06 m^-3 s^-1");
}