#pragma once
#include <vector>

#include "partical.hpp"

namespace gds::chempars {

enum class EquationType {
  ionization,
  elastic,
  excite,
  compound,
  fadding_excitation,
};

struct Equation {
  EquationType         type;
  int                   eq_id;
  double                reaction_velocity;
  std::vector<Partical> reactants;
  std::vector<Partical> products;

  Equation() = default;
  Equation(const std::string &equation_str);

 private:
  static int               id_counter;
  std::vector<std::string> parse_equation_str(const std::string &equation_str);
  EquationType            parse_equation_type(const std::string &type_str);
};

}  // namespace gds::chempars

namespace fmt {
template <>
struct formatter<gds::chempars::EquationType> {
  template <typename ParseContext>
  constexpr auto parse(ParseContext &ctx) {
    return ctx.begin();
  }

  template <typename FormatContext>
  auto format(gds::chempars::EquationType const &type, FormatContext &ctx) {
    switch (type) {
      case gds::chempars::EquationType::ionization:
        return format_to(ctx.out(), "ionization");
      case gds::chempars::EquationType::elastic:
        return format_to(ctx.out(), "elastic");
      case gds::chempars::EquationType::excite:
        return format_to(ctx.out(), "excite");
      case gds::chempars::EquationType::compound:
        return format_to(ctx.out(), "compound");
      case gds::chempars::EquationType::fadding_excitation:
        return format_to(ctx.out(), "fadding_excitation");
      default:
        return format_to(ctx.out(), "unknown");
    }
  }
};

template <>
struct formatter<std::vector<gds::chempars::Partical>> {
  template <typename ParseContext>
  constexpr auto parse(ParseContext &ctx) {
    return ctx.begin();
  }

  template <typename FormatContext>
  auto format(std::vector<gds::chempars::Partical> const &type,
              FormatContext                              &ctx) {
    std::string str = "";
    for (int i = 0; i < type.size() - 1; i++) {
      str += type[i].name + " + ";
    }
    str += type[type.size() - 1].name;
    return format_to(ctx.out(), "{}", str);
  }
};

template <>
struct formatter<gds::chempars::Equation> {
  template <typename ParseContext>
  constexpr auto parse(ParseContext &ctx) {
    return ctx.begin();
  }

  template <typename FormatContext>
  auto format(gds::chempars::Equation const &eq, FormatContext &ctx) {
    return format_to(
        ctx.out(), "equation(type={}, id={}, {} -> {}, reaction_velocity={})",
        eq.type, eq.eq_id, eq.reactants, eq.products, eq.reaction_velocity);
  }
};
}  // namespace fmt