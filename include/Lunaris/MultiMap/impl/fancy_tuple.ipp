namespace Lunaris {
namespace MultiMap {

    template<typename ...Ts>
    template<typename U>
    fancy_tuple<Ts...>& fancy_tuple<Ts...>::operator=(U&& val) requires(contains_type_v<U>) {
        using base_type_input = base_cast<U>;

        std::apply([&](auto&... args) {
            auto assign = [&](auto& arg) {
                using stored_type = std::decay_t<decltype(arg)>;
                
                if constexpr (std::is_same_v<base_type_input, stored_type>) {
                    arg = std::forward<U>(val);
                }
            };
            (assign(args), ...);
        }, static_cast<base_type&>(*this));

        return *this;
    }

    template<typename ...Ts>
    template<typename U>
    bool fancy_tuple<Ts...>::operator==(const U& val) const requires(contains_type_v<U>) {

        using base_type_input = base_cast<U>;
        bool matched_and_equal = false;

        std::apply([&](const auto&... args) {
            auto check = [&](const auto& arg) {
                using stored_type = std::decay_t<decltype(arg)>;

                if constexpr (std::is_same_v<base_type_input, stored_type>) {
                    if (arg == val) {
                        matched_and_equal = true;
                    }
                }
            };
            (check(args), ...);
        }, static_cast<const base_type&>(*this));

        return matched_and_equal;
    }

} // namespace MultiMap
} // namespace Lunaris