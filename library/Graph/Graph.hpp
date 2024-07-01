#pragma once

/**
 * @file Graph.hpp
 * @brief Graph - グラフテンプレート
 * @version 0.1
 * @date 2024-06-14
 */

#include <bits/stdc++.h>
using namespace std;

using Vertex = int;

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

    size_t vertex_{0}, edge_{0};
    vector<vector<ED>> adjacent_list_;

    bool directed_flag_;

    inline void validate(int vertex){
        assert(0 <= vertex && vertex < vertex_);
    }

    public:
    Graph() = default;

    size_t get_vertex_size(){
        return vertex_;
    }

    size_t get_edge_size(){
        return edge_;
    }

    /**
     * @brief 頂点数 `vertex_size` のグラフを構築する。
     * @param vertex_size 頂点数
     * @param directed `true` の場合、有向グラフとして構築する `(default = false)`
     */
    Graph(int vertex_size, bool directed = false) : 
        vertex_(vertex_size), adjacent_list_(vertex_size),
        directed_flag_(directed){}

    /**
     * @brief 2頂点 `s` `t` 間に重み `c` の辺を張る。有向グラフの場合は `s` から `t` への有向辺が、無向グラフの場合は `s` `t` 間の無向辺が張られる。
     * @param s 始点の頂点(有向辺)
     * @param t 終点の頂点(有向辺)
     * @param c 重み `(default = 1)`
     */
    void add_edge(Vertex s, Vertex t, CostType c = 1){
        validate(s);
        validate(t);
        int edge_id = edge_++;
        adjacent_list_[s].push_back(Edge(s, t, c, edge_id));
        if(!directed_flag_){
            adjacent_list_[t].push_back(Edge(t, s, c, edge_id));
        }
    }

    vector<ED> &operator[](Vertex v){
        return adjacent_list_[v];
    }
};

/**
 * @brief グラフの隣接行列を返す。
 * @note verify : https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_A
 * @note 計算量 : O(|V| + |E|)
 * @param G 頂点数 V のグラフ
 * @param not_adjacent_value 2頂点 u, v 間に辺が存在しない場合の値 `(default = 0)`
 * @return vector<vector<CostType>> V × V の隣接行列
 */
template<typename CostType>
vector<vector<CostType>> convert_to_matrix(const Graph<CostType> &G, CostType not_adjacent_value = 0){
    size_t V = G.get_vertex_size();
    vector<vector<CostType>> ret(V, vector<CostType>(V, not_adjacent_value));
    for(int i = 0; i < V; ++i){
        for(Edge<CostType> &e : G[i]){
            ret[i][e.to] = e.cost;
        }
    }
    return ret;
}

template<typename CostType>
Graph<CostType> reverse(const Graph<CostType> &G){
    size_t V = G.get_vertex_size();
    Graph<CostType> ret(V, true);
    for(int i = 0; i < V; ++i){
        for(Edge<CostType> &e : G[i]){
            ret.add_edge(e.to, e.from, e.cost);
        }
    }
    return ret;
}