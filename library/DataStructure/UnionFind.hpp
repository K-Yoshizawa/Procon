#pragma once

/**
 * @brief UnionFind - 素集合データ構造
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Union-Find
 */
struct UnionFind{
    vector<int> data;
 
    UnionFind(size_t sz) : data(sz, -1) {}
 
    /**
     * @brief 要素xと要素yを併合する
     * @param x 併合する要素x
     * @param y 併合する要素y
     * @return true 要素xと要素yがまだ未併合だった場合
     * @return false 要素xと要素yが併合済だった場合
     */
    bool unite(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return false;
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }
 
    /**
     * @brief 要素kが含まれる集合の要素を調べる。
     * @param k 調べたい要素k
     * @return int 含まれる集合の親
     */
    int find(int k){
        if(data[k] < 0) return (k);
        return data[k] = find(data[k]);
    }
 
    /**
     * @brief 要素kが含まれる集合の要素数を求める。
     * @param k 調べたい要素k
     * @return int 集合の要素数
     */
    int size(int k){
        return -data[find(k)];
    }
 
    /**
     * @brief 要素x、要素yが同じ集合に属するか判定する。
     * @param x 判定する要素x
     * @param y 判定する要素y
     * @return true 同じ集合に属している場合
     * @return false 同じ集合に属していない場合
     */
    bool same(int x, int y){
        return find(x) == find(y);
    }

    /**
     * @brief  すべての連結成分を取得する。
     * @retval vector<vector<int>> 
     */
    vector<vector<int>> groups() {
        int n = (int) data.size();
        vector<vector<int>> ret(n);
        for(int i = 0; i < n; i++) {
            ret[find(i)].emplace_back(i);
        }
        ret.erase(remove_if(begin(ret), end(ret), [&](const vector< int > &v) {
            return v.empty();
        }), end(ret));
        return ret;
    }
};