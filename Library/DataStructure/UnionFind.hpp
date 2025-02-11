#pragma once

/**
 * @file UnionFind.hpp
 * @author log K (lX57)
 * @brief Union-Find - 素集合データ構造
 */

#include "../Common.hpp"

class UnionFind{
    public:
    UnionFind(size_t n) : data_(n, -1){}

    int Find(const int k){
        if(data_[k] < 0) return k;
        int r = Find(data_[k]);
        return data_[k] = r;
    }

    bool Same(const int x, const int y){
        return Find(x) == Find(y);
    }

    bool Unite(int x, int y){
        x = Find(x), y = Find(y);
        if(x == y) return false;
        if(data_[x] > data_[y]) swap(x, y);
        data_[x] += data_[y];
        data_[y] = x;
        return true;
    }
    
    size_t Size(int k){
        int v = Find(k);
        return -data_[v];
    }

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

    private:
    vector<int> data_;
};