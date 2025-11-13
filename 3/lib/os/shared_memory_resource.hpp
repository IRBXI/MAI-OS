#pragma once

namespace lib::os {

template <bool owns>
class SharedMemoryResource {
  private:
    const char* name_;
    int fd_;

  public:
    SharedMemoryResource(const char* name);
    ~SharedMemoryResource();

    int GetFileDescriptor();
};

} // namespace lib::os

#include "shared_memory_resource.ipp"
