namespace Lunaris {
namespace MultiMap {
    
    template<typename K, typename V>
    simple_map<K, V>::simple_map(std::initializer_list<std::pair<K, V>> v) 
        : m_vals(v.begin(), v.end())
    {}
    
    template<typename K, typename V>
    simple_map<K, V>::simple_map(const simple_map& v) 
        : m_vals(v.m_vals)
    {}
    
    template<typename K, typename V>
    simple_map<K, V>::simple_map(simple_map&& v) 
        : m_vals(std::move(v.m_vals))
    {}
    
    template<typename K, typename V>
    simple_map<K, V>& simple_map<K, V>::operator=(const simple_map& v) {
        m_vals = v.m_vals;
    }
    
    template<typename K, typename V>
    simple_map<K, V>& simple_map<K, V>::operator=(simple_map&& v) {
        m_vals = std::move(v.m_vals);
    }

    template<typename K, typename V>
    template<typename DK>
    V& simple_map<K, V>::at(const DK& k) {
        for(auto i = m_vals.begin(); i != m_vals.end(); ++i) {
            if (i->first == k)
                return i->second;
        }
        K nk;
        nk = k;
        return m_vals.insert(m_vals.end(), { std::pair<K, V>{std::move(nk), V{}} })->second;
    }

    template<typename K, typename V>
    template<typename DK>
    const V& simple_map<K, V>::at(const DK& k) const {
        for(auto i = m_vals.begin(); i != m_vals.end(); ++i) {
            if (i->first == k)
                return i->second;
        }
        throw MultiMapException("Key not found in map");
    }

    template<typename K, typename V>
    template<typename DK>
    void simple_map<K, V>::set(const DK& k, V v) {
        for(auto i = m_vals.begin(); i != m_vals.end(); ++i) {
            if (i->first == k) {
                i->second = std::move(v);
                return;
            }
        }
        V val{};
        val = std::move(v);
        K nk;
        nk = k;
        m_vals.insert(m_vals.end(), { std::pair<K, V>{std::move(nk), std::move(val)} });
    }

    template<typename K, typename V>
    template<typename DK>
    V& simple_map<K, V>::operator[](const DK& k) {
        return at(k);
    }

    template<typename K, typename V>
    template<typename DK>
    const V& simple_map<K, V>::operator[](const DK& k) const {
        return at(k);
    }

    template<typename K, typename V>
    auto simple_map<K, V>::begin() {
        return m_vals.begin();
    }

    template<typename K, typename V>
    auto simple_map<K, V>::end() {
        return m_vals.end();
    }

    template<typename K, typename V>
    const auto simple_map<K, V>::begin() const {
        return m_vals.begin();
    }

    template<typename K, typename V>
    const auto simple_map<K, V>::end() const {
        return m_vals.end();
    }

} // namespace MultiMap
} // namespace Lunaris