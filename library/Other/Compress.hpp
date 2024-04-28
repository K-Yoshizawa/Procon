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
    /**
     * @brief 配列 `value` を初期値として登録する。
     * @param values 初期配列
     * @param offset 座標圧縮後の先頭の値 (default = 0)
     */
    Compress(vector<T> &values, int offset = 0) : m_value(values), m_offset(offset){}

    /**
     * @brief 座標圧縮を実行する。
     */
    void build(){
        sort(m_value.begin(), m_value.end());
        m_value.erase(unique(m_value.begin(), m_value.end()), m_value.end());
        m_size = m_value.size();
    }

    vector<int> convert(vector<T> &v){
        vector<int> ret;
        for(auto x : v) ret.push_back(to_index(x));
        return ret;
    }

    /**
     * @brief 配列に値を加える。
     * @param value 加える値
     */
    void add(T value){
        m_value.push_back(value);
    }

    /**
     * @brief `value` を対応する `index` に変換する。
     */
    int to_index(T value){
        int ret = (int)(lower_bound(m_value.begin(), m_value.end(), value) - m_value.begin());
        assert(ret < m_size);
        return ret + m_offset;
    }

    /**
     * @brief `index` を対応する `value` に変換する。 
     */
    T to_value(int index){
        return m_value.at(index - m_offset);
    }

    int operator[](T value){
        return to_index(value);
    }

    size_t size(){
        return m_size;
    }
};