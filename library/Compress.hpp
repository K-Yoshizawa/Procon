#pragma once

/**
 * @brief Compress - 座標圧縮
 */

#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Compress{
    int sz;
    vector<int> to_val;
    map<int, int> to_index;

    /**
     * @brief  配列Vで構築する。
     */
    Compress(vector<int> &V){
        for(auto &v : V){
            to_val.emplace_back(v);
        }
        sort(to_val.begin(), to_val.end());
        auto border = unique(to_val.begin(), to_val.end());
        to_val.erase(border, to_val.end());
        sz = to_val.size();
        for(int i = 0; i < sz; ++i){
            to_index[to_val[i]] = i;
        }
    }

    // 値を対応するインデックスに
    inline int vi(int value){
        return to_index[value];
    }

    // インデックスを対応する値に
    inline int iv(int index){
        return to_val[index];
    }
};