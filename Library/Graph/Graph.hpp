#pragma once

#include "../Common.hpp"

using Vertex = int;

template<typename WeightType = int32_t>
struct Edge{
    public:
    Edge() = default;

    Edge(Vertex from_, Vertex to_, WeightType weight_ = 1, int idx_ = -1) :
        from(from_), to(to_), cost(weight_), idx(idx_){}
    
    bool operator<(const Edge<WeightType> &e) const {return cost < e.cost;}

    operator int() const {return to;}

    Vertex from, to;
    WeightType cost;
    int idx;
};

template<typename WeightType = int32_t>
class Graph{
    public:
    Graph() = default;

    Graph(int V) : edge_size_(0), adjacent_list_(V){}
    
    inline void AddUndirectedEdge(Vertex u, Vertex v, WeightType w = 1){
        int idx = edge_size_++;
        adjacent_list_[u].push_back(Edge<WeightType>(u, v, w, idx));
        adjacent_list_[v].push_back(Edge<WeightType>(v, u, w, idx));
    }
    
    inline void AddDirectedEdge(Vertex u, Vertex v, WeightType w = 1){
        int idx = edge_size_++;
        adjacent_list_[u].push_back(Edge<WeightType>(u, v, w, idx));
    }

    inline size_t VertexSize() const {
        return adjacent_list_.size();
    }

    inline size_t EdgeSize() const {
        return edge_size_;
    }

    inline vector<Edge<WeightType>> &operator[](const Vertex v){
        return adjacent_list_[v];
    }

    inline const vector<Edge<WeightType>> &operator[](const Vertex v) const {
        return adjacent_list_[v];
    }
    
    private:
    size_t edge_size_;
    vector<vector<Edge<WeightType>>> adjacent_list_;
};

template<typename WeightType = int32_t>
Graph<WeightType> InputGraph(int N, int M, int padding = -1, bool weighted = false, bool directed = false){
    Graph<WeightType> G(N);
    for(int i = 0; i < M; ++i){
        Vertex u, v; WeightType w = 1;
        cin >> u >> v, u += padding, v += padding;
        if(weighted) cin >> w;
        if(directed) G.AddDirectedEdge(u, v, w);
        else G.AddUndirectedEdge(u, v, w);
    }
    return G;
}