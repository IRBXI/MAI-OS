#include "shared_memory_resource.hpp"

#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <system_error>

namespace lib::os {

SharedMemoryResource::SharedMemoryResource(const char* name) : name_(name) {
    int fd = shm_open(name_, O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        throw std::system_error(errno, std::system_category(),
                                "Couldn't create a shared memory resource");
    }
    fd_ = fd;
}

SharedMemoryResource::~SharedMemoryResource() { shm_unlink(name_); }

int SharedMemoryResource::GetFileDescriptor() { return fd_; }

} // namespace lib::os
