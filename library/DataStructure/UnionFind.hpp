#pragma once

/**
 * @file UnionFind.hpp
 * @author log K (lX57)
 * @brief UnionFind - 素集合データ構造
 * @version 2.0
 * @date 2023-11-12
 */

#include <bits/stdc++.h>
using namespace std;

template<typename T = int>
struct UnionFind{
    private:
    vector<int> __Data;
    vector<T> __Weight;

    T __weight(int k){
        find(k);
        return __Weight[k];
    }

    public:
    /**
     * @brief 要素数 `Size`, 初期重み `Init_Weight` でUnionFindを初期化する。
     * @param Size 要素数
     * @param Init_Weight 重み付きUnionFindの初期重み (option, default = 0)
     */
    UnionFind(int Size, T Init_Weight = 0) : __Data(Size, -1), __Weight(Size, Init_Weight) {}

    /**
     * @brief 要素 `k` の親を返す。ついでに経路圧縮をする。
     * @param k 探索する要素
     * @return int 親要素の番号
     */
    int find(int k){
        if(__Data[k] < 0) return k;
        int r = find(__Data[k]);
        __Weight[k] += __Weight[__Data[k]];
        return __Data[k] = r;
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
        return __weight(y) - __weight(x);
    }

    /**
     * @brief 要素 `x` と要素 `y` を併合する。重みを付与することもできる。
     * @param w `Weight(y) - Weight(x) = w` という制約条件 (option, default = 0)
     * @return 併合済の場合は `false` を返す。
     */
    bool unite(int x, int y, T w = 0){
        w += __weight(x) - __weight(y);
        x = find(x), y = find(y);
        if(x == y) return false;
        if(__Data[x] > __Data[y]) swap(x, y), w = -w;
        __Data[x] += __Data[y];
        __Data[y] = x;
        __Weight[y] = w;
        return true;
    }
};