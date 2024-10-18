#pragma once
#include <vector>

#include "chempars/partical.hpp"
#include "core/physic_constant.hpp"
#include "core/units_extend.hpp"

namespace gds::chempars {

using ccps = gds::physic_constant::cubic_centimeter_per_second_t;

enum class EquationType { ionization, elastic, excite, compound, fadding_excitation, unkown };

struct Equation {
  EquationType          type              = EquationType::unkown;
  int                   eq_id             = -1;
  ccps                  reaction_velocity = ccps(-1);
  std::vector<Partical> reactants;
  std::vector<Partical> products;

  Equation()  = default;
  ~Equation() = default;

  /// @brief Given a equation string, parse it and construct an Equation object
  /// @param equation_str the equation string, e.g. "A -> B + C, ionization, 1.0e+12", the units of reaction velocity is
  /// `cm^3/s`
  explicit Equation(const std::string &equation_str);

 private:
  static int               id_counter;
  std::vector<std::string> parse_equation_str(const std::string &equation_str);
  EquationType             parse_equation_type(const std::string &type_str);

  /// parse the reaction velocity from the equation string
  /// @param velocity_str the string of reaction velocity, not including the unit, and it's units are cm^3/s
  ccps parse_reaction_velocity(const std::string &velocity_str);
};

}  // namespace gds::chempars

namespace fmt {
template <>
struct formatter<gds::chempars::EquationType> : formatter<std::string> {
  inline auto format(const gds::chempars::EquationType &type, format_context &ctx) const -> format_context::iterator {
    std::string type_str;
    switch (type) {
      case gds::chempars::EquationType::ionization:
        type_str = "ionization";
        break;
      case gds::chempars::EquationType::elastic:
        type_str = "elastic";
        break;
      case gds::chempars::EquationType::excite:
        type_str = "excite";
        break;
      case gds::chempars::EquationType::compound:
        type_str = "compound";
        break;
      case gds::chempars::EquationType::fadding_excitation:
        type_str = "fadding_excitation";
        break;
      default:
        type_str = "unknown";
    }
    return formatter<std::string>::format(type_str, ctx);
  }
};

template <>
struct formatter<std::vector<gds::chempars::Partical>> : formatter<std::string> {
  inline auto format(const std::vector<gds::chempars::Partical> &type,
                     format_context                             &ctx) const -> format_context::iterator {
    std::string str = "";
    for (auto &&item : type) {
      str += item.name + " + ";
    }
    str.erase(str.end() - 3, str.end());

    return formatter<std::string>::format(str, ctx);
  }
};

// clang-format off
template <>
struct formatter<gds::chempars::Equation> : formatter<std::string> {
  inline auto format(const gds::chempars::Equation &eq, format_context &ctx) const -> format_context::iterator {
    auto str = fmt::format("equation(type={}, id={}, {} -> {}, reaction_velocity = {})", 
                           eq.type, 
                           eq.eq_id, 
                           eq.reactants,
                           eq.products,
                           units::extend::to_string(eq.reaction_velocity));
    return formatter<std::string>::format(str, ctx);
  }
};
// clang-format on

}  // namespace fmt