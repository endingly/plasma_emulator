#pragma once
#include <units.h>

namespace gds::physic_constant {

// units definition
using cubic_centimeter_per_second =
    units::compound_unit<units::cubed<units::length::centimeter>,
                         units::inverse<units::time::second>>;  // cm^3/s
using cubic_centimeter_per_second_t =
    units::unit_t<cubic_centimeter_per_second>;

// units constant
constexpr auto kelvin = units::temperature::kelvin_t(1);

// physical constant
constexpr auto T_e = 273.15 * kelvin;

}  // namespace gds::physic_constant
