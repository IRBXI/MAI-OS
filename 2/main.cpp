#include "approximate_circle_area.hpp"
#include <iomanip>
#include <iostream>

int main() {
    long double area = lib::math::approximate_circle_area();
    std::cout << "Approximated area: " << std::setprecision(15) << area
              << std::endl;
}
