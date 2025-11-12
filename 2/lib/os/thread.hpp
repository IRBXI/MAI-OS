#pragma once
#include <pthread.h>

namespace lib::os {

typedef void *(*thread_func_t)(void *);

class Thread {
  private:
    pthread_t thread_;
    thread_func_t func_;

  public:
    Thread(thread_func_t func, void *arg);
    Thread(const Thread &) = delete;
    Thread(Thread &&other) noexcept;

    void Join();

    void Detach();
};

} // namespace lib::os
