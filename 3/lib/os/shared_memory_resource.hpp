#pragma once

#include <cstddef>
namespace lib::os {

template <bool owns>
class SharedMemoryResource {
  private:
    const char* name_;
    std::size_t size_;
    int fd_;

  public:
    SharedMemoryResource(const char* name, std::size_t size_);
    ~SharedMemoryResource();

    int GetFileDescriptor();

    std::size_t Size() const noexcept;
};

} // namespace lib::os

#include "shared_memory_resource.ipp"
