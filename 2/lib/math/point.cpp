#include "point.hpp"
#include <cmath>

namespace lib::math {

long double Point::Dist(const Point &a, const Point &b) noexcept {
    const long double x_dif = (a.x - b.x);
    const long double y_dif = (a.y - b.y);
    return sqrtl(powl(x_dif, 2) + powl(y_dif, 2));
}

}; // namespace lib::math
