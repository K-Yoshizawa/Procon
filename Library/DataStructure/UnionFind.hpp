#pragma once

/**
 * @file UnionFind.hpp
 * @author log K (lX57)
 * @brief UnionFind - 素集合データ構造
 * @version 4.0
 * @date 2024-09-05
 */

#include "../Common.hpp"

class UnionFind{
    public:
    /**
     * @brief 要素数 `size` でUnionFindを初期化する。
     * @param size 要素数
     */
    UnionFind(int size) : data_(size, -1){}

    /**
     * @brief 要素 `k` の親を返す。
     * @param k 探索する要素
     * @return int 親要素の番号
     */
    int Find(int k){
        if(data_[k] < 0) return k;
        int r = Find(data_[k]);
        return data_[k] = r;
    }

    /**
     * @brief 要素 `x` と要素 `y` が同じ集合に属しているかを判定する。
     * @param x 要素番号 (0-index)
     * @param y 要素番号 (0-index)
     */
    bool Same(int x, int y){
        return Find(x) == Find(y);
    }

    /**
     * @brief 要素 `x` と要素 `y` を併合する。
     * @param x 要素番号 (0-index)
     * @param y 要素番号 (0-index)
     * @return true 要素 `x` と要素 `y` を併合した (元々未併合だった)
     * @return false 要素 `x` と要素 `y` が既に併合済だった
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
     * @brief 各集合に所属する要素を列挙する。
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
     * @brief 要素 `k` が属する集合の要素数を求める。
     * @param k 要素番号 (0-index)
     * @return int 集合の要素数
     */
    int Size(int k){
        int v = Find(k);
        return -data_[v];
    }

    private:
    vector<int> data_;
};