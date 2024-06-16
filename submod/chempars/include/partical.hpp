#pragma once
#include <fmt/format.h>

#include <string>

namespace gds::chempars {

enum class ParticleType { electron, atom, ion, excite };

struct Partical {
  std::string   name;
  ParticleType type;
  uint8_t       charge;

  Partical(std::string name, ParticleType type, uint8_t charge)
      : name(name), type(type), charge(charge) {}

  Partical(std::string name);
  Partical() = default;
};

}  // namespace gds::chempars

namespace fmt {

template <>
struct formatter<gds::chempars::ParticleType> {
  template <typename ParseContext>
  constexpr auto parse(ParseContext &ctx) {
    return ctx.begin();
  }

  template <typename FormatContext>
  auto format(gds::chempars::ParticleType const &type, FormatContext &ctx) {
    switch (type) {
      case gds::chempars::ParticleType::electron:
        return format_to(ctx.out(), "electron");
      case gds::chempars::ParticleType::atom:
        return format_to(ctx.out(), "atom");
      case gds::chempars::ParticleType::ion:
        return format_to(ctx.out(), "ion");
      case gds::chempars::ParticleType::excite:
        return format_to(ctx.out(), "excite");
    }
    return format_to(ctx.out(), "unknown");
  }
};

template <>
struct formatter<gds::chempars::Partical> {
  template <typename ParseContext>
  constexpr auto parse(ParseContext &ctx) {
    return ctx.begin();
  }

  template <typename FormatContext>
  auto format(gds::chempars::Partical const &part, FormatContext &ctx) {
    return format_to(ctx.out(), "name: {}, type: {}, charge: {}", part.name,
                     part.type, part.charge);
  }
};

}  // namespace fmt
