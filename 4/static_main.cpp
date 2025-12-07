#include <iostream>

#include "area.hpp"
#include "derivative.hpp"

int main() {
    int op;
    float A, B, deltaX;
    while (true) {
        std::cin >> op;
        switch (op) {
        case 1:
            std::cin >> A >> B;
            std::cout << math::Square(A, B) << std::endl;
            break;
        case 2:
            std::cin >> A >> deltaX;
            std::cout << math::Derivative(A, deltaX) << std::endl;
            break;
        }
    }
};
