#pragma once

#include <stdexcept>
#include <tuple>
//#include <string>
//#include <type_traits>
//#include <iostream>

namespace Lunaris {
namespace MultiMap {

    template<typename T> 
    using true_base_cast = std::remove_cv_t<
        std::remove_all_extents_t<
            std::remove_pointer_t<
                std::remove_reference_t<T>
            >
        >
    >;
    template<typename T>
    using base_cast = std::conditional_t<
        std::is_pointer<std::remove_reference_t<T>>::value||std::is_array<std::remove_reference_t<T>>::value,
        std::add_pointer_t<true_base_cast<T>>,
        true_base_cast<T>
    >;


    template<typename... Ts>
    struct fancy_tuple : std::tuple<base_cast<Ts>...> {
        using base_type = std::tuple<base_cast<Ts>...>;
        using base_type::base_type;
        
        template<typename U>
        static constexpr bool contains_type_v = (std::is_same_v<base_cast<U>, base_cast<Ts>> || ...);

        template<typename U>
        fancy_tuple& operator=(U&& val)
        requires(contains_type_v<U>);

        template<typename U>
        bool operator==(const U& val) const
        requires(contains_type_v<U>);
    };


} // namespace MultiMap
} // namespace Lunaris

#include <Lunaris/MultiMap/impl/multimap.ipp>