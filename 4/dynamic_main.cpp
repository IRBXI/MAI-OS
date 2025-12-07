#include <iostream>
#include <string_view>

#include "library_loader.hpp"

static constexpr std::string_view library1_path =
    "/home/rbx/Projects/C++/MAI-OS/4/build/lib/math/libdynamic_math1.so";
static constexpr std::string_view library2_path =
    "/home/rbx/Projects/C++/MAI-OS/4/build/lib/math/libdynamic_math2.so";

static constexpr std::string_view square_name = "Square";
static constexpr std::string_view derivative_name = "Derivative";

using SquareFunc = float (*)(float, float);
using DerivativeFunc = float (*)(float, float);

int main() {
    os::LibraryLoader library_loader1(library1_path);
    os::LibraryLoader library_loader2(library2_path);
    int op;
    float A, B, deltaX;
    int current_version = 1;
    SquareFunc square =
        reinterpret_cast<SquareFunc>(library_loader1.GetFunction(square_name));
    DerivativeFunc derivative = reinterpret_cast<DerivativeFunc>(
        library_loader1.GetFunction(derivative_name));

    auto switch_libraries = [&] {
        if (current_version == 1) {
            square = reinterpret_cast<SquareFunc>(
                library_loader2.GetFunction(square_name));
            derivative = reinterpret_cast<DerivativeFunc>(
                library_loader2.GetFunction(derivative_name));
            current_version = 2;
        } else {
            square = reinterpret_cast<SquareFunc>(
                library_loader1.GetFunction(square_name));
            derivative = reinterpret_cast<DerivativeFunc>(
                library_loader1.GetFunction(derivative_name));
            current_version = 1;
        }
    };

    while (true) {
        std::cin >> op;
        switch (op) {
        case 0:
            switch_libraries();
            break;
        case 1:
            std::cin >> A >> B;
            std::cout << square(A, B) << std::endl;
            break;
        case 2:
            std::cin >> A >> deltaX;
            std::cout << derivative(A, deltaX) << std::endl;
            break;
        }
    }
};
