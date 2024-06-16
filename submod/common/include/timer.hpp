#pragma once
#include <chrono>

namespace gds::common {
class Timer {
 private:
  std::chrono::steady_clock::time_point start_time;
  std::chrono::steady_clock::time_point end_time;
  std::chrono::microseconds             duration;

 public:
  Timer();
  void                      start();
  void                      stop();
  std::chrono::microseconds get_duration();
  void                      pause();
};
};  // namespace gds::common