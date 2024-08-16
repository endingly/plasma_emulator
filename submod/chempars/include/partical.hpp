#pragma once
#include <fmt/format.h>

#include <string>

namespace gds::chempars {

enum class ParticleType { electron, atom, ion, excite };

struct Partical {
  std::string  name;
  ParticleType type;
  uint8_t      charge;

  Partical(std::string name, ParticleType type, uint8_t charge) : name(name), type(type), charge(charge) {}

  Partical(std::string name);
  Partical() = default;
};

}  // namespace gds::chempars

namespace fmt {

template <>
struct formatter<gds::chempars::ParticleType> : formatter<std::string> {
  inline auto format(const gds::chempars::ParticleType &type, format_context &ctx) const -> format_context::iterator {
    std::string type_str;
    switch (type) {
      case gds::chempars::ParticleType::electron:
        type_str = "electron";
        break;
      case gds::chempars::ParticleType::atom:
        type_str = "atom";
        break;
      case gds::chempars::ParticleType::ion:
        type_str = "ion";
        break;
      case gds::chempars::ParticleType::excite:
        type_str = "excite";
        break;
      default:
        type_str = "unknown";
    }
    return formatter<std::string>::format(type_str, ctx);
  }
};

template <>
struct formatter<gds::chempars::Partical> : formatter<std::string> {
  auto format(const gds::chempars::Partical &part, format_context &ctx) const -> format_context::iterator {
    auto str = fmt::format("name: {}, type: {}, charge: {}", part.name, part.type, part.charge);
    return formatter<std::string>::format(str, ctx);
  }
};

}  // namespace fmt
