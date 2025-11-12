#pragma once
#include "mutex.hpp"

namespace lib::math {

const int THREAD_COUNT = 8;

const int POINTS_PER_THREAD = 100000000;

const int TOTAL_POINTS_COUNT = THREAD_COUNT * POINTS_PER_THREAD;

struct ThreadArg {
  public:
    os::Mutex mutex;
    int points_in_circle_count = 0;
};

void *generate_points(void *arg) noexcept;

long double approximate_circle_area();

}; // namespace lib::math
