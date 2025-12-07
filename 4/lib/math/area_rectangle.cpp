#include "area.hpp"

namespace math {

extern "C" {
float Square(float A, float B) noexcept { return A * B; }
}

} // namespace math
