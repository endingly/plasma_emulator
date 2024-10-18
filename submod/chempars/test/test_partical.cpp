#include <gtest/gtest.h>

#include "chempars/partical.hpp"

TEST(ParticalTest, format_out) {
  using namespace gds::chempars;
  Partical p;
  p.name   = "H";
  p.charge = 0;
  p.type   = ParticleType::atom;
  fmt::print("{}\n", p);
}

TEST(ParticalTest, constrcut) {
  using namespace gds::chempars;
  Partical p2("O");
  fmt::print("{}\n", p2);
  EXPECT_EQ(p2.type, ParticleType::atom);
}