#include "thread.hpp"
#include <pthread.h>
#include <system_error>

namespace lib::os {

Thread::Thread(thread_func_t func, void *arg) : func_(func) {
    int err = pthread_create(&thread_, nullptr, func_, arg);
    if (err == -1) {
        throw std::system_error(errno, std::system_category(),
                                "Couldn't create a thread");
    }
}

Thread::Thread(Thread &&other) noexcept
    : thread_(other.thread_), func_(other.func_) {
    other.thread_ = -1;
    other.func_ = nullptr;
}

void Thread::Join() {
    int err = pthread_join(thread_, nullptr);
    if (err == -1) {
        throw std::system_error(errno, std::system_category(),
                                "Couldn't join a thread");
    }
}

void Thread::Detach() {
    int err = pthread_detach(thread_);
    if (err == -1) {
        throw std::system_error(errno, std::system_category(),
                                "Couldn't detach a thread");
    }
}

} // namespace lib::os
