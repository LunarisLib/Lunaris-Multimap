#pragma once

#include <vector>

#include <Lunaris/MultiMap/exception.h>
#include <Lunaris/MultiMap/base_type.h>
#include <Lunaris/MultiMap/fancy_tuple.h>

namespace Lunaris {
namespace MultiMap {

    /**
     * @brief Single Key Multiple Values pair template
     * 
     * @tparam `Key` Used as key in the map (single type)
     * @tparam `Ts` Values a key holds
     */
    template<typename Key, typename... Ts>
    using skmv_pair = std::pair<base_cast<Key>, fancy_tuple<Ts...>>;

    /**
     * @brief Multiple Keys Single Value pair template
     * 
     * @tparam `Value` What value type the map holds (single type)
     * @tparam `Ts` Keys types for the map
     */
    template<typename Value, typename... Ts>
    using mksv_pair = std::pair<fancy_tuple<Ts...>, base_cast<Value>>;

    /**
     * @brief Generic simple map-like class
     * 
     * @tparam `K` Key type (may be object)
     * @tparam `V` Value type (may be object)
     */
    template<typename K, typename V>
    class simple_map {
    public:
        simple_map() = default;

        /**
         * @brief Construct a new simple map object using initializer list
         * 
         * @param `v` list variable to initialize from
         */
        simple_map(std::initializer_list<std::pair<K, V>> v);

        /**
         * @brief Copy other map of same kind
         * 
         * @param `v` another map
         */
        simple_map(const simple_map& v);

        /**
         * @brief Move other map to this
         * 
         * @param `v` another map to move from
         */
        simple_map(simple_map&& v);

        /**
         * @brief Copy other map of same kind
         * 
         * @param `v` another map
         */
        simple_map& operator=(const simple_map& v);
        
        /**
         * @brief Move other map to this
         * 
         * @param `v` another map to move from
         */
        simple_map& operator=(simple_map&& v);

        /**
         * @brief Get value tied to key, or create value for key
         * 
         * @param `k` key to match or create
         */
        template<typename DK>
        V& at(const DK& k);

        /**
         * @brief Get value tied to key, or exception if not found
         * 
         * @param `k` key to match
         */
        template<typename DK>
        const V& at(const DK& k) const;

        /**
         * @brief Set value directly with key and value. Replaces if match
         * 
         * @param `k` key to match
         * @param `v` value to store tied to key
         */
        template<typename DK>
        void set(const DK& k, V v);


        /**
         * @brief Get value tied to key, or create value for key
         * 
         * @param `k` key to match or create
         */
        template<typename DK>
        V& operator[](const DK& k);

        /**
         * @brief Get value tied to key, or exception if not found
         * 
         * @param `k` key to match
         */
        template<typename DK>
        const V& operator[](const DK& k) const;

        /**
         * @brief Begin of internal vector storing the pairs
         * 
         * @return `auto` iterator of vector
         */
        auto begin();

        /**
         * @brief End of internal vector storing the pairs
         * 
         * @return `auto` iterator of vector
         */
        auto end();

        /**
         * @brief Begin of internal vector storing the pairs
         * 
         * @return `auto` iterator of vector
         */
        const auto begin() const;

        /**
         * @brief End of internal vector storing the pairs
         * 
         * @return `auto` iterator of vector
         */
        const auto end() const;
    private:
        std::vector<std::pair<K, V>> m_vals;
    };

    /**
     * @brief Template of simple map ready for Single Key Multiple Values
     * 
     * @tparam Key Single type key
     * @tparam Ts Multiple types to store as value
     */
    template<typename Key, typename... Ts>
    using skmv_map = simple_map<base_cast<Key>, fancy_tuple<Ts...>>;

    /**
     * @brief Template of simple map ready for Multiple Key Single Values
     * 
     * @tparam Key Multiple types key
     * @tparam Ts Single type to store as value
     */
    template<typename Value, typename... Ts>
    using mksv_map = simple_map<fancy_tuple<Ts...>, base_cast<Value>>;

} // namespace MultiMap
} // namespace Lunaris

#include <Lunaris/MultiMap/impl/multi_map.ipp>