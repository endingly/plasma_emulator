#pragma once
#include <vector>

#include "partical.hpp"

namespace gds::chempars {

enum class equation_type {
  ionization,
  elastic,
  excite,
  compound,
  fadding_excitation,
};

struct equation {
  equation_type         type;
  int                   eq_id;
  double                threshold;
  std::vector<partical> reactants;
  std::vector<partical> products;

  equation() = default;
  equation(std::string equation_str);
};

}  // namespace gds::chempars

namespace fmt {
template <>
struct formatter<gds::chempars::equation_type> {
  template <typename ParseContext>
  constexpr auto parse(ParseContext &ctx) {
    return ctx.begin();
  }

  template <typename FormatContext>
  auto format(gds::chempars::equation_type const &type, FormatContext &ctx) {
    switch (type) {
      case gds::chempars::equation_type::ionization:
        return format_to(ctx.out(), "ionization");
      case gds::chempars::equation_type::elastic:
        return format_to(ctx.out(), "elastic");
      case gds::chempars::equation_type::excite:
        return format_to(ctx.out(), "excite");
      case gds::chempars::equation_type::compound:
        return format_to(ctx.out(), "compound");
      case gds::chempars::equation_type::fadding_excitation:
        return format_to(ctx.out(), "fadding_excitation");
      default:
        return format_to(ctx.out(), "unknown");
    }
  }
};

template <>
struct formatter<std::vector<gds::chempars::partical>> {
  template <typename ParseContext>
  constexpr auto parse(ParseContext &ctx) {
    return ctx.begin();
  }

  template <typename FormatContext>
  auto format(std::vector<gds::chempars::partical> const &type,
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
struct formatter<gds::chempars::equation> {
  template <typename ParseContext>
  constexpr auto parse(ParseContext &ctx) {
    return ctx.begin();
  }

  template <typename FormatContext>
  auto format(gds::chempars::equation const &eq, FormatContext &ctx) {
    return format_to(
        ctx.out(), "equation(type={}, id={}, {} -> {}, threshold={})", eq.type,
        eq.eq_id, eq.reactants, eq.products, eq.threshold);
  }
};
}  // namespace fmt