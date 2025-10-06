#include "prime.hpp"
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <unistd.h>

int main() {
    std::ofstream outFile("composites.txt");
    int n;
    signed char answer = 0;
    while (read(STDIN_FILENO, &n, sizeof(int))) {
        if (n < 0 or lib::math::IsPrime(n)) {
            answer = -1;
            write(STDOUT_FILENO, &answer, sizeof(signed char));
            std::exit(0);
        }
        outFile << n << std::endl;
        write(STDOUT_FILENO, &answer, sizeof(signed char));
    }
}
