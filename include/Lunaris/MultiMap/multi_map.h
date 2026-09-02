#pragma once

#include <vector>

#include <Lunaris/MultiMap/exception.h>
#include <Lunaris/MultiMap/base_type.h>
#include <Lunaris/MultiMap/fancy_tuple.h>

namespace Lunaris {
namespace MultiMap {

    template<typename Key, typename... Ts>
    using skmv_pair = std::pair<base_cast<Key>, fancy_tuple<Ts...>>;

    template<typename Value, typename... Ts>
    using mksv_pair = std::pair<fancy_tuple<Ts...>, base_cast<Value>>;

    template<typename K, typename V>
    class simple_map {
    public:
        simple_map() = default;
        simple_map(std::initializer_list<std::pair<K, V>>);
        simple_map(const simple_map&);
        simple_map(simple_map&&);
        simple_map& operator=(const simple_map&);
        simple_map& operator=(simple_map&&);

        template<typename DK>
        V& at(const DK&);
        template<typename DK>
        const V& at(const DK&) const;

        template<typename DK>
        void set(const DK&, V);

        template<typename DK>
        V& operator[](const DK&);
        template<typename DK>
        const V& operator[](const DK&) const;

        auto begin();
        auto end();
        const auto begin() const;
        const auto end() const;
    private:
        std::vector<std::pair<K, V>> m_vals;
    };

    template<typename Key, typename... Ts>
    using skmv_map = simple_map<base_cast<Key>, fancy_tuple<Ts...>>;

    template<typename Value, typename... Ts>
    using mksv_map = simple_map<fancy_tuple<Ts...>, base_cast<Value>>;

} // namespace MultiMap
} // namespace Lunaris

#include <Lunaris/MultiMap/impl/multi_map.ipp>