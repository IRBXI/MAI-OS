#include "process.hpp"
#include <cassert>
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    lib::os::Pipe pipe_to_child;
    lib::os::Pipe pipe_from_child;

    char program_name[] = "child";
    CreateProcessWithPipesConnection(program_name, pipe_to_child,
                                     pipe_from_child);

    int n;

    signed char answer;

    while (std::cin >> n) {
        pipe_to_child.Send(&n, sizeof(int));

        // We read one byte from the child proccess
        // if we receive -1 we terminate the proccess
        // otherwise we continue to read the numbers from stdin
        pipe_from_child.Receive(&answer, sizeof(answer));

        if (answer == -1) {
            std::exit(0);
        }
    }
}
