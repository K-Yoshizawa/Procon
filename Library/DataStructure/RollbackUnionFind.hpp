#pragma once

/**
 * @file RollbackUnionFind.hpp
 * @author lX57
 * @brief Rollback Union-Find - Rollback 可能 Union-Find
 */

#include "../Common.hpp"

class RollbackUnionFind{
    public:
    /**
     * @brief 要素数 `size` で Union-Find を初期化します。
     * @note 要素番号は 0-index です。
     * @param size 要素数
     */
    RollbackUnionFind(size_t size) : data_(size, -1){}

    /**
     * @brief 要素 `k` が属する集合の代表元を返します。
     * @param k 探索する要素
     * @return 要素 `k` が属する集合の代表元
     */
    int Find(const int k) const {
        if(data_[k] < 0) return k;
        return Find(data_[k]);
    }

    /**
     * @brief 要素 `x` と要素 `y` が同じ集合に属しているかを判定します。
     * @param x 要素番号
     * @param y 要素番号
     * @return 同じ集合に属しているか
     */
    bool Same(const int x, const int y) const {
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
        history_.push({x, data_[x]});
        history_.push({y, data_[y]});
        if(x == y) return false;
        if(data_[x] > data_[y]) swap(x, y);
        data_[x] += data_[y];
        data_[y] = x;
        return true;
    }

    /**
     * @brief 現在の状態を保存します。別の状態を保存している場合、上書きします。
     */
    void Record(){
        record_ = history_.size();
    }

    /**
     * @brief 直前の `Unite` 操作を取り消します。
     */
    void Undo(){
        auto [y, dy] = history_.top();
        history_.pop();
        data_[y] = dy;
        auto [x, dx] = history_.top();
        history_.pop();
        data_[x] = dx;
    }

    /**
     * @brief `Record` で記録した状態までロールバックします。
     */
    void Rollback(){
        int state = record_;
        while(state < (int)history_.size()) Undo();
    }

    /**
     * @brief 各集合に所属する要素を列挙します。
     * @return vector<vector<int>> 各集合に所属する要素の一覧
     */
    vector<vector<int>> Group() const {
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
    int Size(const int k) const {
        return -data_[Find(k)];
    }

    private:
    vector<int> data_;
    stack<pair<int, int>> history_;
    int record_;
};