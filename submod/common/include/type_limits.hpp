#pragma once

namespace gds::common {

class TypeLimitHelper {
 private:
  static constexpr bool isPerfectSquareHelper(unsigned int num, unsigned int lo, unsigned int hi) {
    {
      if (lo > hi) {
        return false;
      }
      unsigned int mid    = lo + (hi - lo) / 2;
      unsigned int square = mid * mid;
      if (square == num) {
        return true;
      } else if (square < num) {
        return isPerfectSquareHelper(num, mid + 1, hi);
      } else {
        return isPerfectSquareHelper(num, lo, mid - 1);
      }
    }
  }

 public:
  /// @brief the function checks if a number is a perfect square or not
  /// @param num the number to be checked
  /// @return true if the number is a perfect square, false otherwise
  static constexpr bool isPerfectSquare(unsigned int num) {
    return num == 0 || num == 1 || isPerfectSquareHelper(num, 1, num);
  }
};

template <size_t N>
concept SquareRootNumber = gds::common::TypeLimitHelper::isPerfectSquare(N);

}  // namespace gds::common