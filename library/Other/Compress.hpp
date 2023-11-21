/**
 * @file Compress.hpp
 * @author log K (lX57)
 * @brief Compress - 座標圧縮
 * @version 1.1
 * @date 2023-08-24
 */

#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Compress{
    int sz, offset;
    vector<T> to_val;
    map<T, int> to_index;

    /**
     * @brief 配列Vを用いて座標圧縮配列を生成する。
     * @param V 生成元の配列
     * @param start 座標圧縮後の値の先頭の値。(default = 0)
     */
    Compress(vector<T> &V, int start = 0) : offset(start){
        for(auto &v : V){
            to_val.emplace_back(v);
        }
        sort(to_val.begin(), to_val.end());
        auto border = unique(to_val.begin(), to_val.end());
        to_val.erase(border, to_val.end());
        sz = to_val.size();
        for(int i = 0; i < sz; ++i){
            to_index[to_val[i]] = i + offset;
        }
    }

    /**
     * @brief 値を対応するインデックスに変換する。
     * @param value 変換する値
     * @return int 変換された値(オフセットの存在に注意)
     */
    inline int vi(T value){
        return to_index[value];
    }

    /**
     * @brief インデックスを対応する値に変換する。
     * @param index 変換する値(オフセットの存在に注意)
     * @return T 変換された値
     */
    inline T iv(int index){
        return to_val[index - offset];
    }

    /**
     * @brief 値の入った配列を全てインデックスに変換した配列を返す。
     * @note 元の値は不要で、大小関係だけ分かれば良い場合に使える
     * @param Value 変換する値が格納された配列
     * @return vector<int> 変換したインデックスが格納された配列
     */
    vector<int> convert(const vector<T> &Value){
        vector<int> ret;
        for(auto v : Value) ret.push_back(vi(v));
        return ret;
    }
};