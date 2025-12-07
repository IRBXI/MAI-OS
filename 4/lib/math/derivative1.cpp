#include "derivative.hpp"

#include <cmath>

namespace math {

extern "C" {
float Derivative(float A, float deltaX) {
    float res = (std::cos(A + deltaX) - std::cos(A)) / deltaX;
    return res;
}
}

} // namespace math
