#pragma once

#include <cstddef>

#include "shared_memory_resource.hpp"

namespace lib::os {

template <typename T>
class MemoryMap {
  private:
    T* buffer_;
    std::size_t size_;

  public:
    MemoryMap() = delete;

    template <bool owns>
    MemoryMap(SharedMemoryResource<owns>& smr);
    ~MemoryMap();

    T& operator[](std::size_t pos) noexcept;
    const T& operator[](std::size_t pos) const noexcept;

    std::size_t Size() const noexcept;

    void Sync();
};

} // namespace lib::os

#include "memory_map.ipp"
