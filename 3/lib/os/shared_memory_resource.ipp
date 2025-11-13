#pragma once

#include "shared_memory_resource.hpp"

#include <cstdio>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <system_error>
#include <unistd.h>

namespace lib::os {

template <bool owns>
SharedMemoryResource<owns>::SharedMemoryResource(const char* name,
                                                 std::size_t size) {
    int fd = shm_open(name, O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        throw std::system_error(errno, std::system_category(),
                                "Couldn't create a shared memory resource");
    }
    if constexpr (owns) {
        int err = ftruncate(fd, size);
        if (err == -1) {
            throw std::system_error(
                errno, std::system_category(),
                "couldn't resize the file under the shared memory resource");
        }
    }
    name_ = name;
    size_ = size;
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

template <bool owns>
std::size_t SharedMemoryResource<owns>::Size() const noexcept {
    return size_;
}

} // namespace lib::os
