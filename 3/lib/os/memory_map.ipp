#pragma once

#include "memory_map.hpp"

#include <cassert>
#include <cstddef>
#include <sys/mman.h>
#include <system_error>
#include <unistd.h>

namespace lib::os {

template <typename T>
MemoryMap<T>::MemoryMap(SharedMemoryResource& smr, std::size_t len) {
    void* buffer = mmap(NULL, len * sizeof(T), PROT_READ | PROT_WRITE,
                        MAP_SHARED, smr.GetFileDescriptor(), 0);
    if (buffer == MAP_FAILED) {
        throw std::system_error(errno, std::system_category(),
                                "Couldn't create a memory map");
    }
    int err = ftruncate(smr.GetFileDescriptor(), len * sizeof(T));
    if (err == -1) {
        throw std::system_error(
            errno, std::system_category(),
            "Couldn't resize the file under the shared memory resource");
    }

    buffer_ = reinterpret_cast<T*>(buffer);
    len_ = len;
}

template <typename T>
MemoryMap<T>::~MemoryMap() {
    munmap(buffer_, len_);
}

template <typename T>
T& MemoryMap<T>::operator[](std::size_t pos) noexcept {
    assert(pos < len_);
    return buffer_[pos];
}

template <typename T>
const T& MemoryMap<T>::operator[](std::size_t pos) const noexcept {
    assert(pos < len_);
    return buffer_[pos];
}

template <typename T>
void MemoryMap<T>::Sync() {
    int err = msync(buffer_, len_, MS_ASYNC);
    if (err == -1) {
        throw std::system_error(errno, std::system_category(),
                                "Couldn't sync the mapped memory");
    }
}

} // namespace lib::os
