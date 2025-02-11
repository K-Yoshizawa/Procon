/**
 * @file WeightedUnionFind.hpp
 * @author log K (lX57)
 * @brief Weighted Union-Find - 重み付き素集合データ構造
 */

#include "../Common.hpp"

template<typename Abel = int32_t>
class WeightedUnionFind{
    public:
    WeightedUnionFind(int n) : data_(size, -1), weight_(size, Abel{}){}

    int Find(const int k){
        if(data_[k] < 0) return k;
        int r = Find(data_[k]);
        weight_[k] += weight_[data_[k]];
        return data_[k] = r;
    }

    Abel Weight(const int k){
        Find(k);
        return weight_[k];
    }

    Abel Diff(const int x, const int y){
        return Weight(y) - Weight(x);
    }

    bool Same(const int x, const int y){
        return Find(x) == Find(y);
    }

    bool Unite(int x, int y, Abel w){
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