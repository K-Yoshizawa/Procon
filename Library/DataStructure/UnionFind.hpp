#pragma once

/**
 * @file UnionFind.hpp
 * @author log K (lX57)
 * @brief Union-Find - 素集合データ構造
 * @version 5.0
 * @date 2025-02-07
 */

#include "../Common.hpp"

class UnionFind{
    public:
    /**
     * @brief 要素数 `size` で Union-Find を初期化します。
     * @note 要素番号は 0-index です。
     * @param size 要素数
     */
    UnionFind(size_t size) : data_(size, -1){}

    /**
     * @brief 要素 `k` が属する集合の代表元を返します。
     * @param k 探索する要素
     * @return 要素 `k` が属する集合の代表元
     */
    int Find(int k){
        if(data_[k] < 0) return k;
        int r = Find(data_[k]);
        return data_[k] = r;
    }

    /**
     * @brief 要素 `x` と要素 `y` が同じ集合に属しているかを判定します。
     * @param x 要素番号
     * @param y 要素番号
     * @return 同じ集合に属しているか
     */
    bool Same(int x, int y){
        return Find(x) == Find(y);
    }

    /**
     * @brief 要素 `x` と要素 `y` を併合します。併合した場合は `true` を返します。
     * @param x 要素番号
     * @param y 要素番号
     * @return 併合を行ったか
     */
    bool Unite(int x, int y){
        x = Find(x), y = Find(y);
        if(x == y) return false;
        if(data_[x] > data_[y]) swap(x, y);
        data_[x] += data_[y];
        data_[y] = x;
        return true;
    }

    /**
     * @brief 各集合に所属する要素を列挙します。
     * @return vector<vector<int>> 各集合に所属する要素の一覧
     */
    vector<vector<int>> Group(){
        vector<vector<int>> ret(data_.size());
        for(int i = 0; i < data_.size(); ++i){
            ret[Find(i)].emplace_back(i);
        }
        ret.erase(remove_if(begin(ret), end(ret), [&](vector<int> &v){
            return v.empty();
        }), end(ret));
        return ret;
    }

    /**
     * @brief 要素 `k` が属する集合の要素数を求めます。
     * @param k 要素番号
     * @return int 集合の要素数
     */
    int Size(int k){
        int v = Find(k);
        return -data_[v];
    }

    private:
    vector<int> data_; // 代表元は-(集合の要素数)を、非代表元は代表元の番号を経路圧縮により持つ
};