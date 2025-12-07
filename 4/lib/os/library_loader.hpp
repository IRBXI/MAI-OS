#pragma once

#include <string_view>

namespace os {

class LibraryLoader {
private:
    void* library_handle_;

public:
    LibraryLoader(std::string_view library_path);
    ~LibraryLoader();
    void* GetFunction(std::string_view function_name);
};

} // namespace os
