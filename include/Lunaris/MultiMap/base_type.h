#pragma once

namespace Lunaris {
namespace MultiMap {

    /**
     * @brief Casts type way back to base type (removes pointer, lvalue, rvalue, everything)
     */
    template<typename T> 
    using true_base_cast = std::remove_cv_t<
        std::remove_all_extents_t<
            std::remove_pointer_t<
                std::remove_reference_t<T>
            >
        >
    >;

    /**
     * @brief Casts type way back, but keeps if it is pointer or not
     */
    template<typename T>
    using base_cast = std::conditional_t<
        std::is_pointer<std::remove_reference_t<T>>::value||std::is_array<std::remove_reference_t<T>>::value,
        std::add_pointer_t<true_base_cast<T>>,
        true_base_cast<T>
    >;

} // namespace MultiMap
} // namespace Lunaris