#pragma once

#include <units.h>

#include "units_extend.hpp"

namespace gds::physic_constant {

#pragma region units constant
constexpr auto kelvin = units::temperature::kelvin_t(1);
#pragma endregion

#pragma region physical constant
constexpr auto T_e      = units::temperature::kelvin_t(273.15);                          // 室温下的电子温度
constexpr auto Omega    = units::reaction_rate::cubic_centimeter_per_second_t(1.19e-4);  // 电子碰撞频率
constexpr auto Qe       = units::constants::e;                                           // 电子电量
constexpr auto EPSILON0 = units::constants::epsilon0;                                    // 真空介电常数
#pragma endregion
}  // namespace gds::physic_constant
