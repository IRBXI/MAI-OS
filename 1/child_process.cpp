#include "prime.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>

int main() {
    std::cerr << "FUCK YOU" << std::endl;
    std::ofstream outFile("composites.txt");
    int n;
    while (std::cin >> n) {
        std::cerr << n << std::endl;
        if (n < 0 or IsPrime(n)) {
            std::cout << static_cast<signed char>(-1);
            std::cout.flush();
            std::exit(0);
        }
        outFile << n << std::endl;
        std::cout << static_cast<signed char>(0);
        std::cout.flush();
    }
}
