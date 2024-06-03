#pragma once
#include <fmt/format.h>

#include <string>

namespace gds::chempars {

enum class particle_type { electron, atom, ion, excite };

struct partical {
  std::string   name;
  particle_type type;
  uint8_t       charge;

  partical(std::string name, particle_type type, uint8_t charge)
      : name(name), type(type), charge(charge) {}

  partical(std::string name);
  partical() = default;
};

}  // namespace gds::chempars

namespace fmt {

template <>
struct formatter<gds::chempars::particle_type> {
  template <typename ParseContext>
  constexpr auto parse(ParseContext &ctx) {
    return ctx.begin();
  }

  template <typename FormatContext>
  auto format(gds::chempars::particle_type const &type, FormatContext &ctx) {
    switch (type) {
      case gds::chempars::particle_type::electron:
        return format_to(ctx.out(), "electron");
      case gds::chempars::particle_type::atom:
        return format_to(ctx.out(), "atom");
      case gds::chempars::particle_type::ion:
        return format_to(ctx.out(), "ion");
      case gds::chempars::particle_type::excite:
        return format_to(ctx.out(), "excite");
    }
    return format_to(ctx.out(), "unknown");
  }
};

template <>
struct formatter<gds::chempars::partical> {
  template <typename ParseContext>
  constexpr auto parse(ParseContext &ctx) {
    return ctx.begin();
  }

  template <typename FormatContext>
  auto format(gds::chempars::partical const &part, FormatContext &ctx) {
    return format_to(ctx.out(), "name: {}, type: {}, charge: {}", part.name,
                     part.type, part.charge);
  }
};

}  // namespace fmt
