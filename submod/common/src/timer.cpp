#include "timer.hpp"

namespace gds::common {

Timer::Timer() { start_time = std::chrono::steady_clock::now(); }

void Timer::start() { start_time = std::chrono::steady_clock::now(); }

void Timer::stop() {
  end_time = std::chrono::steady_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
}

std::chrono::microseconds Timer::get_duration() { return duration; }

void Timer::pause() {
  end_time = std::chrono::steady_clock::now();
  duration += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
  start_time = end_time;
}

};  // namespace gds::common