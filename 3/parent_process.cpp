#include <cassert>
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

#include "memory_map.hpp"
#include "process.hpp"
#include "shared_memory_resource.hpp"

int main() {
    lib::os::SharedMemoryResource<true> smr("/lab_shared_memory",
                                            2 * sizeof(int));

    // The mapped memory basically consists of 2 ints
    // first one desceribes who's message is currently in the buffer
    // 1 means parent process
    // 2 means child process
    // the second int is just an int we are currently translating through the
    // buffer
    lib::os::MemoryMap<int> memory_map(smr);

    // We initially think that we just received a message from the child process
    // because it makes the code on the child side a bit easier
    memory_map[0] = 2;
    memory_map.Sync();

    char program_name[] = "child";
    lib::os::CreateProcess(program_name);

    int n;

    while (std::cin >> n) {
        memory_map[0] = 1;
        memory_map[1] = n;
        memory_map.Sync();

        // Busy waiting for the child proccess to write back
        // (Basically a spinlock)
        while (memory_map[0] == 1) {
        }

        // If we receive -1 we terminate the proccess
        // otherwise we continue to read the numbers from stdin
        if (memory_map[1] == -1) {
            break;
        }
    }
}
