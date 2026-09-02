#pragma once

#include <stdexcept>

namespace Lunaris {
namespace MultiMap {

    class MultiMapException : public std::runtime_error {
    public:
        explicit MultiMapException(const std::string&) noexcept;
        explicit MultiMapException(const char*) noexcept;

        const char* what() const noexcept;
    };

} // namespace MultiMap
} // namespace Lunaris