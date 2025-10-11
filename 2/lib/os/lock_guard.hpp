#pragma once
#include "mutex.hpp"
#include <pthread.h>

namespace lib::os {

class LockGuard {
  private:
    Mutex &mutex_;

  public:
    LockGuard() = delete;

    LockGuard(Mutex &mutex) noexcept;

    ~LockGuard() noexcept;
};

} // namespace lib::os
