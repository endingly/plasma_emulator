#include <gtest/gtest.h>

#include "partical.hpp"

TEST(ParticalTest, format_out) {
  using namespace gds::chempars;
  partical p;
  p.name   = "H";
  p.charge = 0;
  p.type   = particle_type::atom;
  fmt::print("{}\n", p);
}

TEST(ParticalTest, constrcut) {
  using namespace gds::chempars;
  partical p2("O");
  fmt::print("{}\n", p2);
  EXPECT_EQ(p2.type, particle_type::atom);
}