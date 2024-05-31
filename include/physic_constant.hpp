#pragma once
#include <units.h>

namespace gds::physic_constant {

constexpr auto kelvin = units::temperature::kelvin_t(1);
constexpr auto T_e    = 273.15 * kelvin;

}  // namespace gds::physic_constant
