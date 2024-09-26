#pragma once
#include <units.h>
namespace gds::config {

constexpr auto   xmax     = units::length::centimeter_t(0.24);                       // x 轴最大长度
constexpr auto   ymax     = units::length::centimeter_t(0.2);                        // y 轴最大长度
constexpr int    x_cells  = 73;                                                      // x 轴网格数
constexpr int    y_cells  = 61;                                                      // y 轴网格数
constexpr auto   pressure = units::pressure::torr_t(15);                             // 压强
constexpr auto   voltage  = units::voltage::volt_t(800);                             // 电压
constexpr auto   dt       = units::time::second_t(1e-20);                            // 时间步长
constexpr auto   dx       = xmax / (x_cells - 1);                                    // x 方向空间步长
constexpr auto   dy       = ymax / (y_cells - 1);                                    // y 方向空间步长
constexpr float  gama     = 0;                                                       // 二次电子发射系数
constexpr int    top_wall = 7;                                                       // 顶壁
constexpr int    bot_wall = 67;                                                      // 底壁
constexpr float  f_He     = 0.0f;                                                    // 氦气分子比例
constexpr float  f_CO2    = 1.0f;                                                    // 二氧化碳分子比例
constexpr double init_MN  = pressure.value() * 133.3 * 1e-6 / (1.38 * 1e-23 * 300);  // 初始中性粒子数

}  // namespace gds::config