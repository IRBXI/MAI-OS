#include "mutex.hpp"
#include <pthread.h>
#include <system_error>

namespace lib::os {

Mutex::Mutex() {
    int err = pthread_mutex_init(&mutex_, nullptr);
    if (err == -1) {
        throw std::system_error(errno, std::system_category(),
                                "Couldn't init a mutex");
    }
}

Mutex::~Mutex() noexcept { pthread_mutex_destroy(&mutex_); }

void Mutex::Lock() noexcept { pthread_mutex_lock(&mutex_); }

void Mutex::Unlock() noexcept { pthread_mutex_unlock(&mutex_); }

}; // namespace lib::os
