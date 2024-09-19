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
  EquationType          type;
  int                   eq_id;
  double                reaction_velocity;
  std::vector<Partical> reactants;
  std::vector<Partical> products;

  Equation()  = default;
  ~Equation() = default;
  Equation(const std::string &equation_str);

 private:
  static int               id_counter;
  std::vector<std::string> parse_equation_str(const std::string &equation_str);
  EquationType             parse_equation_type(const std::string &type_str);
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
    if (type.size() > 0) {
      for (int i = 0; i < type.size() - 1; i++) {
        str += type[i].name + " + ";
      }
      if (type.size() > 1) str += type[type.size() - 1].name;
    } else
      str = "none";
    return formatter<std::string>::format(str, ctx);
  }
};

template <>
struct formatter<gds::chempars::Equation> : formatter<std::string> {
  inline auto format(const gds::chempars::Equation &eq, format_context &ctx) const -> format_context::iterator {
    auto str = fmt::format("equation(type={}, id={}, {} -> {}, reaction_velocity={})", eq.type, eq.eq_id, eq.reactants,
                           eq.products, eq.reaction_velocity);
    return formatter<std::string>::format(str, ctx);
  }
};
}  // namespace fmt