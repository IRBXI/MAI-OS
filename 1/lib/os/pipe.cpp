#include "pipe.hpp"
#include <sys/types.h>
#include <system_error>
#include <unistd.h>

namespace lib::os {

Pipe::Pipe() {
    int err = pipe(pipe_fd_);
    if (err == -1) {
        throw std::system_error(errno, std::system_category(),
                                "Couldn't create a pipe");
    }
}

Pipe::~Pipe() {
    close(pipe_fd_[0]);
    close(pipe_fd_[1]);
}

int Pipe::ReadDescriptor() noexcept { return pipe_fd_[0]; }

int Pipe::WriteDescriptor() noexcept { return pipe_fd_[1]; }

void Pipe::CloseReadDescriptor() noexcept { close(pipe_fd_[0]); }

void Pipe::CloseWriteDescriptor() noexcept { close(pipe_fd_[1]); }

void Pipe::Send(const void *buf, std::size_t count) {
    ssize_t bytes_written = write(pipe_fd_[1], buf, count);
    if (bytes_written == -1) {
        throw std::system_error(errno, std::system_category(),
                                "Couldn't send data");
    }
}

void Pipe::Receive(void *buf, std::size_t count) {
    ssize_t bytes_read = read(pipe_fd_[0], buf, count);
    if (bytes_read == -1) {
        throw std::system_error(errno, std::system_category(),
                                "Couldn't recieve data");
    }
}

} // namespace lib::os
