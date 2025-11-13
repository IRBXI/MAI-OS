#pragma once

#include "memory_map.hpp"

#include <cassert>
#include <cstddef>
#include <stdexcept>
#include <sys/mman.h>
#include <system_error>
#include <unistd.h>

namespace lib::os {

template <typename T>
template <bool owns>
MemoryMap<T>::MemoryMap(SharedMemoryResource<owns>& smr) {
    if (smr.Size() % sizeof(T) != 0) {
        throw std::invalid_argument(
            "The shared memory resource size should be divisible by size of T");
    }
    size_ = smr.Size() / sizeof(T);
    void* buffer = mmap(NULL, smr.Size(), PROT_READ | PROT_WRITE, MAP_SHARED,
                        smr.GetFileDescriptor(), 0);
    if (buffer == MAP_FAILED) {
        throw std::system_error(errno, std::system_category(),
                                "Couldn't create a memory map");
    }
    buffer_ = reinterpret_cast<T*>(buffer);
}

template <typename T>
MemoryMap<T>::~MemoryMap() {
    munmap(buffer_, size_);
}

template <typename T>
T& MemoryMap<T>::operator[](std::size_t pos) noexcept {
    assert(pos < size_);
    return buffer_[pos];
}

template <typename T>
const T& MemoryMap<T>::operator[](std::size_t pos) const noexcept {
    assert(pos < size_);
    return buffer_[pos];
}

template <typename T>
void MemoryMap<T>::Sync() {
    int err = msync(buffer_, size_, MS_ASYNC);
    if (err == -1) {
        throw std::system_error(errno, std::system_category(),
                                "Couldn't sync the mapped memory");
    }
}

template <typename T>
std::size_t MemoryMap<T>::Size() const noexcept {
    return size_;
}

} // namespace lib::os
