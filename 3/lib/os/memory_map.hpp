#pragma once

#include <cstddef>

#include "shared_memory_resource.hpp"

namespace lib::os {

template <typename T>
class MemoryMap {
  private:
    T* buffer_;
    std::size_t len_;

  public:
    MemoryMap() = delete;
    MemoryMap(SharedMemoryResource& smr, std::size_t len);
    ~MemoryMap();

    T& operator[](std::size_t pos) noexcept;
    const T& operator[](std::size_t pos) const noexcept;

    void Sync();
};

} // namespace lib::os

#include "memory_map.ipp"
