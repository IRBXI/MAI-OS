#include <cstddef>

class Pipe {
  public:
    Pipe();
    ~Pipe();

    int ReadDescriptor() noexcept;
    int WriteDescriptor() noexcept;

    void CloseReadDescriptor() noexcept;
    void CloseWriteDescriptor() noexcept;

    void Send(const void *buf, std::size_t count);
    void Receive(void *buf, std::size_t cound);

  private:
    int pipe_fd_[2];
};
