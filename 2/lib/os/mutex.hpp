#pragma once
#include <pthread.h>

namespace lib::os {

class Mutex {
  private:
    pthread_mutex_t mutex_;

  public:
    Mutex();
    ~Mutex() noexcept;

    Mutex(const Mutex &) = delete;

    void Lock() noexcept;
    void Unlock() noexcept;
};

}; // namespace lib::os
