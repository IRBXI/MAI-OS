#include "library_loader.hpp"

#include <dlfcn.h>
#include <system_error>

namespace os {

LibraryLoader::LibraryLoader(std::string_view library_path) {
    library_handle_ = dlopen(library_path.data(), RTLD_LAZY);
    if (!library_handle_) {
        throw std::system_error(0, std::system_category(), dlerror());
    }
}

void* LibraryLoader::GetFunction(std::string_view function_name) {
    void* function_ptr = dlsym(library_handle_, function_name.data());
    if (!function_ptr) {
        throw std::system_error(0, std::system_category(), dlerror());
    }
    return function_ptr;
}

LibraryLoader::~LibraryLoader() {
    if (library_handle_) {
        dlclose(library_handle_);
    }
}

} // namespace os
