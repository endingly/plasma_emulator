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