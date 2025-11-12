#include <cassert>
#include <cstdlib>
#include <fstream>
#include <unistd.h>

#include "memory_map.hpp"
#include "prime.hpp"
#include "shared_memory_resource.hpp"

int main() {
    std::ofstream compositesFile("composites.txt");

    lib::os::SharedMemoryResource smr("/lab_shared_memory");

    lib::os::MemoryMap<int> memory_map(smr, 2);

    int n;
    while (true) {
        // Busy waiting for the parent process to write
        while (memory_map[0] == 2) {
        }
        n = memory_map[1];

        if (n < 0 or lib::math::IsPrime(n)) {
            memory_map[1] = -1;
            memory_map[0] = 2;
            std::exit(0);
        }

        compositesFile << n << std::endl;

        memory_map[1] = 0;
        memory_map[0] = 2;
    }
}
