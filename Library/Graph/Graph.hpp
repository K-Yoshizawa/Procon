#pragma once

#include "../Common.hpp"

using Vertex = int;

template<typename CostType = int32_t>
struct Edge{
    public:
    Edge() = default;

    Edge(Vertex from_, Vertex to_, CostType cost_ = 1, int idx_ = -1) :
        from(from_), to(to_), cost(cost_), idx(idx_){}
    
    operator int() const {return to;}

    Vertex from, to;
    CostType cost;
    int idx;
};

template<typename CostType = int32_t>
class Graph{
    public:
    Graph() = default;

    Graph(int n) : vertex_size_(n), edge_size_(0), adjacent_list_(n){}
    
    inline void AddUndirectedEdge(Vertex u, Vertex v, CostType w = 1){
        int idx = edge_size_++;
        adjacent_list_[u].push_back(Edge<CostType>(u, v, w, idx));
        adjacent_list_[v].push_back(Edge<CostType>(v, u, w, idx));
    }
    
    inline void AddDirectedEdge(Vertex u, Vertex v, CostType w = 1){
        int idx = edge_size_++;
        adjacent_list_[u].push_back(Edge<CostType>(u, v, w, idx));
    }

    inline size_t VertexSize() const {
        return adjacent_list_.size();
    }

    inline vector<Edge<CostType>> &operator[](const int v){
        return adjacent_list_[v];
    }

    inline const vector<Edge<CostType>> &operator[](const int v) const {
        return adjacent_list_[v];
    }
    
    private:
    size_t vertex_size_, edge_size_;
    vector<vector<Edge<CostType>>> adjacent_list_;
};

template<typename CostType = int32_t>
Graph<CostType> InputGraph(int N, int M, int padding = -1, bool weighted = false, bool directed = false){
    Graph<CostType> G(N);
    for(int i = 0; i < M; ++i){
        Vertex u, v; CostType w = 1;
        cin >> u >> v, u += padding, v += padding;
        if(weighted) cin >> w;
        if(directed) G.AddDirectedEdge(u, v, w);
        else G.AddUndirectedEdge(u, v, w);
    }
    return G;
}