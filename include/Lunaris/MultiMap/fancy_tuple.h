#pragma once

#include <tuple>

#include <Lunaris/MultiMap/base_type.h>

namespace Lunaris {
namespace MultiMap {

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
        template<typename U>
        
        bool operator!=(const U& val) const
        requires(contains_type_v<U>);

        template <typename V>
        constexpr operator V&() & noexcept
        requires (((std::same_as<V, Ts> ? 1 : 0) + ...) == 1) {
            return std::get<V>(*this);
        }

        template <typename V>
        constexpr operator const V&() const & noexcept
        requires (((std::same_as<V, Ts> ? 1 : 0) + ...) == 1) {
            return std::get<V>(*this);
        }

        template <typename V>
        constexpr operator V() && noexcept
        requires (((std::same_as<V, Ts> ? 1 : 0) + ...) == 1) {
            return std::get<V>(std::move(*this));
        }
    };

} // namespace MultiMap
} // namespace Lunaris

#include <Lunaris/MultiMap/impl/fancy_tuple.ipp>