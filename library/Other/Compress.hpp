/**
 * @file Compress.hpp
 * @author log_K (lX57)
 * @brief Compress - 座標圧縮
 * @version 2.0
 * @date 2024-02-04
 */

#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Compress{
    private:
    size_t m_size;
    int m_offset;
    vector<T> m_value;

    public:
    Compress(vector<T> &value, int offset = 0) : m_value(value){
        sort(m_value.begin(), m_value.end());
        m_value.erase(unique(m_value.begin(), m_value.end()), m_value.end());
        m_size = m_value.size();
    }

    int to_index(T value){
        int ret = (int)(lower_bound(m_value.begin(), m_value.end(), value) - m_value.begin());
        assert(ret < m_size);
        return ret;
    }

    T to_value(int index){
        return m_value.at(index);
    }

    int operator[](T value){
        return to_index(value);
    }
};