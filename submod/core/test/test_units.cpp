#include <gtest/gtest.h>

#include "config.hpp"
#include "physic_constant.hpp"
#include "units_extend.hpp"

TEST(UnitsTest, TestUnits) {
  std::cout << gds::physic_constant::T_e << std::endl;
  std::cout << gds::physic_constant::cubic_centimeter_per_second_t(1.0) << std::endl;
}

TEST(UnitsTest, TestConfig) {
  std::cout << gds::config::xmax << std::endl;
  std::cout << gds::config::ymax << std::endl;
  std::cout << gds::config::pressure << std::endl;
  std::cout << gds::config::voltage << std::endl;
}

TEST(UnitsTest, Test_Extend_To_string) {
  gds::physic_constant::cubic_centimeter_per_second_t ccs(1.0);
  auto                                                s = units::extend::to_string(ccs);
  std::cout << s << std::endl;
}