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
    size_t size_;
    int offset_;
    vector<T> value_;

    public:
    /**
     * @brief 配列 `value` を初期値として登録する。
     * @param values 初期配列
     * @param offset 座標圧縮後の先頭の値 (default = 0)
     */
    Compress(vector<T> &values, int offset = 0) : value_(values), offset_(offset){}

    /**
     * @brief 座標圧縮を実行する。
     */
    void build(){
        sort(value_.begin(), value_.end());
        value_.erase(unique(value_.begin(), value_.end()), value_.end());
        size_ = value_.size();
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
        value_.push_back(value);
    }

    /**
     * @brief `value` を対応する `index` に変換する。
     */
    int to_index(T value){
        int ret = (int)(lower_bound(value_.begin(), value_.end(), value) - value_.begin());
        assert(ret < size_);
        return ret + offset_;
    }

    /**
     * @brief `index` を対応する `value` に変換する。 
     */
    T to_value(int index){
        return value_.at(index - offset_);
    }

    int operator[](T value){
        return to_index(value);
    }

    size_t size(){
        return size_;
    }
};