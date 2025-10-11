#include "thread.hpp"
#include <pthread.h>
#include <system_error>

namespace lib::os {

Thread::Thread(thread_func_t func, void *arg) {
    int err = pthread_create(&thread_, nullptr, func, arg);
    if (err == -1) {
        throw std::system_error(errno, std::system_category(),
                                "Couldn't create a thread");
    }
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
