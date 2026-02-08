#pragma once

#include "../Common.hpp"
#include "Tree.hpp"

template<typename CostType>
class EulerTour{
    public:
    using F = function<CostType(CostType)>;

    EulerTour(){}

    EulerTour(RootedTree<CostType> &T, bool one_index = false) :
            T(T),
            vertex_size_(T.get_vertex_size()),
            in_time_(T.get_vertex_size()),
            out_time_(T.get_vertex_size()),
            one_index_(one_index){
        dfs(T.get_root());
    }

    int GetIn(const Vertex v) const {
        return in_time_.at(v - one_index_);
    }

    int GetOut(const Vertex v) const {
        return out_time_.at(v - one_index_);
    }

    pair<int, int> GetPair(const Vertex v) const {
        return make_pair(in_time_.at(v - one_index_), out_time_.at(v - one_index_));
    }

    template<typename Type>
    vector<Type> ConvertVector(const vector<Type> &value, const F in_converter, const F out_converter){
        vector<Type> ret(2 * vertex_size_);
        for(int i = 0; i < vertex_size_; ++i){
            int in_idx = in_time_.at(i), out_idx = out_time_.at(i);
            ret[in_idx] = in_converter(value.at(i));
            ret[out_idx] = out_converter(value.at(i));
        }
        return ret;
    }

    private:
    int time_{0}, one_index_, vertex_size_;

    RootedTree<CostType> &T;
    vector<int> in_time_, out_time_;

    void dfs(Vertex v){
        in_time_[v] = time_++;
        for(Vertex c : T.get_child(v)){
            dfs(c);
        }
        out_time_[v] = time_++;
    }
};