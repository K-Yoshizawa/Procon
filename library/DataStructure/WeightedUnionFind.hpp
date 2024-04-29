#pragma once

/**
 * @file WeightedUnionFind.hpp
 * @author log K (lX57)
 * @brief Weighted UnionFind - 重み付き素集合データ構造
 * @version 1.0
 * @date 2024-04-26
 */

#include <bits/stdc++.h>
using namespace std;

template<typename T = int>
struct WeightedUnionFind{
    private:
    vector<int> data_;
    vector<T> weight_;

    T get_weight_(int k){
        find(k);
        return weight_[k];
    }

    public:
    /**
     * @brief 要素数 `Size`, 初期重み `Init_Weight` でWeightedUnionFindを初期化する。
     * @param Size 要素数
     * @param Init_Weight 重み付きWeightedUnionFindの初期重み (option, default = 0)
     */
    WeightedUnionFind(int Size, T Init_Weight = 0) : data_(Size, -1), weight_(Size, Init_Weight) {}

    /**
     * @brief 要素 `k` の親を返す。ついでに経路圧縮をする。
     * @param k 探索する要素
     * @return int 親要素の番号
     */
    int find(int k){
        if(data_[k] < 0) return k;
        int r = find(data_[k]);
        weight_[k] += weight_[data_[k]];
        return data_[k] = r;
    }

    /**
     * @brief 要素 `x` と要素 `y` が同じ集合に属しているかを判定する。
     */
    bool same(int x, int y){
        return find(x) == find(y);
    }

    /**
     * @brief `Weight(y) - Weight(x)` を計算する。
     * @return T `Weight(y) - Weight(x)` の値
     */
    T diff(int x, int y){
        return get_weight_(y) - get_weight_(x);
    }

    /**
     * @brief 要素 `x` と要素 `y` を併合する。重みを付与することもできる。
     * @param w `Weight(y) - Weight(x) = w` という制約条件 (option, default = 0)
     * @return 併合済の場合は `false` を返す。
     */
    bool unite(int x, int y, T w = 0){
        w += get_weight_(x) - get_weight_(y);
        x = find(x), y = find(y);
        if(x == y) return false;
        if(data_[x] > data_[y]) swap(x, y), w = -w;
        data_[x] += data_[y];
        data_[y] = x;
        weight_[y] = w;
        return true;
    }

    vector<vector<int>> group(){
        vector<vector<int>> ret(data_.size());
        for(int i = 0; i < data_.size(); ++i){
            ret[find(i)].emplace_back(i);
        }
        ret.erase(remove_if(begin(ret), end(ret), [&](vector<int> &v){
            return v.empty();
        }), end(ret));
        return ret;
    }
};