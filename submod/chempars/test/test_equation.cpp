#include <gtest/gtest.h>

#include "chempars/equation.hpp"

TEST(EquationTest, TestEquation) {
  using namespace gds::chempars;
  using vec_part = std::vector<Partical>;
  Equation e;
  e.eq_id             = 1;
  e.reaction_velocity = ccps(3e-10);
  e.type              = EquationType::ionization;

  Partical p1, p2, p3;
  p1.name   = "H2O";
  p1.charge = 0;
  p1.type   = ParticleType::atom;

  p2.name   = "O2";
  p2.charge = 0;
  p2.type   = ParticleType::atom;

  p3.name   = "H+";
  p3.charge = 1;
  p3.type   = ParticleType::ion;

  vec_part reacs = {p2, p3};
  vec_part prods = {p1};

  e.reactants = reacs;
  e.products  = prods;

  fmt::print("{}\n", e);
}

TEST(EquationTest, TestParse) {
  using namespace gds::chempars;
  std::string str = "e + Ar^+ -> Ar^*, excite, 3e-10";
  Equation    e(str);
  fmt::print("{}\n", e);
}