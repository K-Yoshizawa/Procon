#pragma once

#include "../Common.hpp"

using Vertex = int;

template<typename Ordered = int32_t>
struct Edge{
    public:
    Edge() = default;

    Edge(Vertex from_, Vertex to_, Ordered weight_ = 1, int idx_ = -1) :
        from(from_), to(to_), cost(weight_), idx(idx_){}
    
    bool operator<(const Edge<Ordered> &e) const {return cost < e.cost;}

    operator int() const {return to;}

    Vertex from, to;
    Ordered cost;
    int idx;
};

template<typename Ordered = int32_t>
class Graph{
    public:
    Graph() = default;

    Graph(int V) : edge_size_(0), adjacent_list_(V){}
    
    inline void AddUndirectedEdge(Vertex u, Vertex v, Ordered w = 1){
        int idx = edge_size_++;
        adjacent_list_[u].push_back(Edge<Ordered>(u, v, w, idx));
        adjacent_list_[v].push_back(Edge<Ordered>(v, u, w, idx));
    }
    
    inline void AddDirectedEdge(Vertex u, Vertex v, Ordered w = 1){
        int idx = edge_size_++;
        adjacent_list_[u].push_back(Edge<Ordered>(u, v, w, idx));
    }

    inline size_t VertexSize() const {
        return adjacent_list_.size();
    }

    inline size_t EdgeSize() const {
        return edge_size_;
    }

    inline vector<Edge<Ordered>> &operator[](const Vertex v){
        return adjacent_list_[v];
    }

    inline const vector<Edge<Ordered>> &operator[](const Vertex v) const {
        return adjacent_list_[v];
    }
    
    private:
    size_t edge_size_;
    vector<vector<Edge<Ordered>>> adjacent_list_;
};