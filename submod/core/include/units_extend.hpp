#pragma once
#include <units.h>
#include <concepts>
#include <sstream>

namespace units::extend {

template <typename T>
concept Units = requires(T t, std::ostream& os) {
  { t.abbreviation() } -> std::same_as<const char*>;
  { t.name() } -> std::same_as<const char*>;
  t.value();
  { os << t } -> std::same_as<std::ostream&>;
};

template <Units T>
inline std::string to_string(T t) {
  std::stringstream ss;
  ss << t;
  return ss.str();
};

}  // namespace units::extend
