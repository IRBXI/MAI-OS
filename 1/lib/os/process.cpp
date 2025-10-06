#include "process.hpp"
#include <cerrno>
#include <iostream>
#include <sys/wait.h>
#include <system_error>
#include <unistd.h>

namespace {
const int STDIN = 0;
const int STDOUT = 1;
} // namespace

// After the call to this function pipe_to_child's read descriptor will be
// closed and pipe_from_child's write descriptor will be closed since the copies
// of them will be used in the child proccess
void CreateProcessWithPipesConnection(char *const program_name,
                                      Pipe &pipe_to_child,
                                      Pipe &pipe_from_child) {
    pid_t pid = fork();
    if (pid == -1) {
        throw std::system_error(errno, std::system_category(),
                                "Couldn't fork a process");
    }
    if (pid > 0) {
        return;
    }
    // We are already in the child proccess

    std::cerr << getpid() << '\n';

    dup2(pipe_to_child.ReadDescriptor(), STDIN);
    dup2(pipe_from_child.WriteDescriptor(), STDOUT);

    pipe_to_child.CloseReadDescriptor();
    pipe_from_child.CloseWriteDescriptor();

    char *const argv[] = {program_name, nullptr};
    int err = execv(program_name, argv);
    if (err == -1) {
        throw std::system_error(errno, std::system_category(),
                                "Couldn't exec on a forked process");
    }
}
