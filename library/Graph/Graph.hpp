#pragma once

/**
 * @file Graph.hpp
 * @brief Graph - グラフテンプレート
 * @version 0.1
 * @date 2024-06-14
 */

#include <bits/stdc++.h>
using namespace std;

template<typename CostType>
struct Edge{
    int from{-1}, to{-1}, id{-1};
    CostType cost{1};

    Edge() = default;
    Edge(int from, int to, CostType cost, int id = -1) : from(from), to(to), cost(cost), id(id){}
};

template<typename CostType = int32_t>
class Graph{
    using ED = Edge<CostType>;

    int vertex_{0}, edge_{0};
    vector<vector<ED>> adjacent_list_;

    bool directed_flag_;

    inline void validate(int vertex){
        assert(0 <= vertex && vertex < vertex_);
    }

    public:
    Graph() = default;

    /**
     * @brief 頂点数 `vertex_size` のグラフを構築する。
     * @param vertex_size 頂点数
     * @param directed `true` の場合、有向グラフとして構築する `(default = false)`
     */
    Graph(int vertex_size, bool directed = false) : 
        vertex_(vertex_size), adjacent_list_(vertex_size),
        directed_flag_(directed){

    }

    void add_edge(int s, int t, CostType c = 1){
        validate(s);
        validate(t);
        int edge_id = edge_++;
        adjacent_list_[s].push_back(Edge(s, t, c, edge_id));
        if(!directed_flag_){
            adjacent_list_[t].push_back(Edge(t, s, c, edge_id));
        }
    }

    /**
     * @brief グラフの隣接行列を返す。
     * @note verify : https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_A
     * @param not_adjacent_value 2頂点 u, v 間に辺が存在しない場合の値 `(default = 0)`
     * @return vector<vector<CostType>> V × V の隣接行列
     */
    vector<vector<CostType>> convert_to_matrix(CostType not_adjacent_value = 0){
        vector<vector<CostType>> ret(vertex_, vector<CostType>(vertex_, not_adjacent_value));
        for(int i = 0; i < vertex_; ++i){
            for(ED e : adjacent_list_[i]){
                ret[i][e.to] = e.cost;
            }
        }
        return ret;
    }
};