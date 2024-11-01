#pragma once
#include <units.h>

#include <ratio>
#include <sstream>

namespace units {

UNIT_ADD(volume, cubic_centimeter, cubic_centimeter, cc,
         units::unit<std::ratio<1, 1000000>, units::volume::cubic_meter>);

UNIT_ADD(reaction_rate, cubic_centimeter_per_second, cubic_centimeter_per_second, ccps,
         compound_unit<inverse<volume::cc>, inverse<time::second>>);

};  // namespace units

namespace units::extend {

template <typename T>
concept UnitsLike = units::traits::is_unit_t<T>::value;

template <UnitsLike T>
inline std::string to_string(T t) {
  std::stringstream ss;
  ss << t;
  return ss.str();
};

}  // namespace units::extend
