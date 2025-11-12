#pragma once

namespace lib::os {

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
