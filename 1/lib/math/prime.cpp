#include "prime.hpp"

namespace lib::math {

bool IsPrime(int n) {
    if (n == 0 or n == 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

} // namespace lib::math
