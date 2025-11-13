#pragma once

#include "shared_memory_resource.hpp"

#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <system_error>

namespace lib::os {

template <bool owns>
SharedMemoryResource<owns>::SharedMemoryResource(const char* name)
    : name_(name) {
    int fd = shm_open(name_, O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        throw std::system_error(errno, std::system_category(),
                                "Couldn't create a shared memory resource");
    }
    fd_ = fd;
}

template <bool owns>
int SharedMemoryResource<owns>::GetFileDescriptor() {
    return fd_;
}

template <bool owns>
SharedMemoryResource<owns>::~SharedMemoryResource() {
    if constexpr (owns) {
        shm_unlink(name_);
    }
}

} // namespace lib::os
