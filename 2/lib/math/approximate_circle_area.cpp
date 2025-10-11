#include "approximate_circle_area.hpp"
#include "lock_guard.hpp"
#include "point.hpp"
#include "thread.hpp"
#include <random>
#include <vector>

namespace lib::math {

namespace {

std::random_device rd;

std::mt19937 gen(rd());

bool is_inside_circle(const Point &a) {
    const Point p0 = {0.0, 0.0};

    return Point::Dist(p0, a) <= 1.0;
}

} // namespace

void *generate_points(void *arg) noexcept {
    ThreadArg *thread_arg = reinterpret_cast<ThreadArg *>(arg);

    std::uniform_real_distribution<long double> distribution(-1.0, 1.0);

    for (std::size_t i = 0; i < POINTS_PER_THREAD; ++i) {
        const Point a = {distribution(gen), distribution(gen)};

        if (is_inside_circle(a)) {
            os::LockGuard lock_guard(thread_arg->mutex);
            thread_arg->points_in_circle_count++;
        }
    }

    return nullptr;
}

long double approximate_circle_area() {
    ThreadArg thread_arg = {os::Mutex(), 0};

    std::vector<os::Thread> threads;

    for (std::size_t i = 0; i < THREAD_COUNT; ++i) {
        threads.emplace_back(generate_points, &thread_arg);
    }

    for (std::size_t i = 0; i < THREAD_COUNT; ++i) {
        threads[i].Join();
    }

    return 4.0 * thread_arg.points_in_circle_count /
           static_cast<long double>(TOTAL_POINTS_COUNT);
}

} // namespace lib::math
