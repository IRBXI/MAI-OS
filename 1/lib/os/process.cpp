#include "process.hpp"
#include <cerrno>
#include <sys/wait.h>
#include <system_error>
#include <unistd.h>

namespace lib::os {

// After the call to this function pipe_to_child's read descriptor will be
// closed and pipe_from_child's write descriptor will be closed since the copies
// of them will be used in the child process
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

    dup2(pipe_to_child.ReadDescriptor(), STDIN_FILENO);
    dup2(pipe_from_child.WriteDescriptor(), STDOUT_FILENO);

    pipe_to_child.CloseReadDescriptor();
    pipe_from_child.CloseWriteDescriptor();

    char *const argv[] = {program_name, nullptr};
    int err = execv(program_name, argv);
    if (err == -1) {
        throw std::system_error(errno, std::system_category(),
                                "Couldn't exec on a forked process");
    }
}

} // namespace lib::os
