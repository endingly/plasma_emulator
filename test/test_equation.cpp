#include <gtest/gtest.h>

#include "equation.hpp"

TEST(EquationTest, TestEquation) {
  using namespace gds::chempars;
  using vec_part = std::vector<partical>;
  equation e;
  e.eq_id     = 1;
  e.threshold = 3e-10;
  e.type      = equation_type::ionization;

  partical p1, p2, p3;
  p1.name   = "H2O";
  p1.charge = 0;
  p1.type   = particle_type::atom;

  p2.name   = "O2";
  p2.charge = 0;
  p2.type   = particle_type::atom;

  p3.name   = "H+";
  p3.charge = 1;
  p3.type   = particle_type::ion;

  vec_part reacs = {p2, p3};
  vec_part prods = {p1};

  e.reactants = reacs;
  e.products  = prods;

  fmt::print("{}\n", e);
}