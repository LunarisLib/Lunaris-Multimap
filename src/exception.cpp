#include <Lunaris/MultiMap/exception.h>

namespace Lunaris {
namespace MultiMap {

    MultiMapException::MultiMapException(const std::string& msg) noexcept
        : std::runtime_error(msg)
    {
    }

    MultiMapException::MultiMapException(const char* msg) noexcept
        : std::runtime_error(msg)
    {
    }

    const char* MultiMapException::what() const noexcept {
        return std::runtime_error::what();
    }

} // namespace MultiMap
} // namespace Lunaris