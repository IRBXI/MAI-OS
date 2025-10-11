#include "lock_guard.hpp"

namespace lib::os {

LockGuard::LockGuard(Mutex &mutex) noexcept : mutex_(mutex) { mutex_.Lock(); }

LockGuard::~LockGuard() noexcept { mutex_.Unlock(); }

}; // namespace lib::os
