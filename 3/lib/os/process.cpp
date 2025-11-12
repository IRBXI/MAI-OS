#include "process.hpp"

#include <cerrno>
#include <sys/wait.h>
#include <system_error>
#include <unistd.h>

namespace lib::os {

void CreateProcess(char* const program_name) {
    pid_t pid = fork();
    if (pid == -1) {
        throw std::system_error(errno, std::system_category(),
                                "Couldn't fork a process");
    }
    if (pid > 0) {
        return;
    }
    // We are already in the child proccess
    char* const argv[] = {program_name, nullptr};
    int err = execv(program_name, argv);
    if (err == -1) {
        throw std::system_error(errno, std::system_category(),
                                "Couldn't exec on a forked process");
    }
}

} // namespace lib::os
