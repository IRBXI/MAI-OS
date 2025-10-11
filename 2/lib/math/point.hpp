#pragma once

namespace lib::math {

struct Point {
  public:
    long double x, y;

    static long double Dist(const Point &a, const Point &b) noexcept;
};

}; // namespace lib::math
