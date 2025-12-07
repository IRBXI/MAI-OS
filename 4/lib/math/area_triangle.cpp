#include "area.hpp"

namespace math {

extern "C" {
float Square(float A, float B) noexcept { return 0.5f * A * B; }
}

} // namespace math
