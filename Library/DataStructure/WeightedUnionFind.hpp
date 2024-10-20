/**
 * @file WeightedUnionFind.hpp
 * @author log K (lX57)
 * @brief Weighted UnionFind - 重み付き素集合データ構造
 * @version 2.0
 * @date 2024-09-05
 */

#include "../Common.hpp"

template<typename Abel = int32_t>
class WeightedUnionFind{
    public:
    WeightedUnionFind(int size) : data_(size, -1), weight_(size, Abel{}){}

    int Find(int k){
        if(data_[k] < 0) return k;
        int r = Find(data_[k]);
        weight_[k] += weight_[data_[k]];
        return data_[k] = r;
    }

    Abel Weight(int k){
        Find(k);
        return weight_[k];
    }

    Abel Diff(int x, int y){
        return Weight(y) - Weight(x);
    }

    bool Same(int x, int y){
        return Find(x) == Find(y);
    }

    bool Relate(int x, int y, Abel w){
        w += Weight(x) - Weight(y);
        x = Find(x), y = Find(y);
        if(x == y) return false;
        if(data_[x] > data_[y]) swap(x, y), w = -w;
        data_[x] += data_[y];
        data_[y] = x;
        weight_[y] = w;
        return true;
    }

    private:
    vector<int> data_;
    vector<Abel> weight_;
};