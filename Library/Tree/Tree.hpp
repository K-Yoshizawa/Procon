#pragma once

#include "../Graph/Graph.hpp"

template<typename WeightType = int32_t>
Graph<WeightType> InputTree(int V, int padding = -1, bool weighted = false){
    Graph<WeightType> G(V);
    for(int i = 0; i < V - 1; ++i){
        Vertex u, v; WeightType w = 1;
        cin >> u >> v, u += padding, v += padding;
        if(weighted) cin >> w;
        G.AddUndirectedEdge(u, v, w);
    }
    return G;
}

template<typename WeightType = int32_t>
Graph<WeightType> InputRootedTreeChild(int V, int padding = -1){
    Graph<WeightType> G(V);
    for(Vertex u = 0; u < V; ++u){
        int k; cin >> k;
        for(int i = 0; i < k; ++i){
            Vertex v; cin >> v, v += padding;
            G.AddUndirectedEdge(u, v);
        }
    }
    return G;
}

template<typename WeightType = int32_t>
Graph<WeightType> InputRootedTreeParent(int V, int padding = -1){
    Graph<WeightType> G(V);
    for(Vertex u = 1; u < V; ++u){
        Vertex v; cin >> v, v += padding;
        G.AddUndirectedEdge(u, v);
    }
    return G;
}

template<typename WeightType = int32_t>
vector<vector<Vertex>> RootedTreeAdjacentList(const Graph<WeightType> &T, const Vertex r = 0){
    int V = T.VertexSize();
    vector<vector<Vertex>> ret(V);
    auto rec = [&](auto &self, Vertex u, Vertex p) -> void {
        for(Vertex v : T[u]){
            if(v == p) continue;
            ret[u].push_back(v);
            self(self, v, u);
        }
    };
    rec(rec, r, -1);
    return ret;
}

template<typename WeightType>
vector<Vertex> CalculateTreeParent(Graph<WeightType> &T, Vertex r = 0){
    int V = T.VertexSize();
    vector<Vertex> ret(V, -1);
    auto rec = [&](auto &self, Vertex u) -> void {
        for(Vertex v : T[u]){
            if(v == ret[u]) continue;
            ret[v] = u;
            self(self, v);
        }
    };
    rec(rec, r);
    return ret;
}

template<typename WeightType>
vector<WeightType> CalculateTreeCost(Graph<WeightType> &T, Vertex r = 0){
    int V = T.VertexSize();
    vector<WeightType> ret(V);
    auto rec = [&](auto &self, Vertex u, Vertex p) -> void {
        for(const Edge<WeightType> &e : T[u]){
            Vertex v = e.to;
            if(v == p) continue;
            ret[v] = e.cost;
            self(self, v, u);
        }
    };
    rec(rec, r, -1);
    return ret;
}

template<typename WeightType>
vector<int> CalculateTreeDepth(Graph<WeightType> &T, Vertex r = 0){
    int V = T.VertexSize();
    vector<int> ret(V, 0);
    auto rec = [&](auto &self, Vertex u, Vertex p, int d) -> void {
        ret[u] = d;
        for(Vertex v : T[u]){
            if(v == p) continue;
            self(self, v, u, d + 1);
        }
    };
    rec(rec, r, -1, 0);
    return ret;
}

template<typename WeightType>
vector<WeightType> CalculateTreeDistance(Graph<WeightType> &T, Vertex r = 0){
    int V = T.VertexSize();
    vector<WeightType> ret(V, WeightType(INF));
    auto rec = [&](auto &self, Vertex u) -> void {
        for(const Edge<WeightType> &e : T[u]){
            if(ret[e.to] > ret[u] + e.cost){
                ret[e.to] = ret[u] + e.cost;
                self(self, e.to);
            }
        }
    };
    ret[r] = 0;
    rec(rec, r);
    return ret;
}

template<typename WeightType>
vector<int> CalculateSubtreeSize(Graph<WeightType> &tree, Vertex r = 0){
    int V = tree.VertexSize();
    vector<int> ret(V, 1);
    auto rec = [&](auto self, Vertex u, Vertex p) -> int {
        for(const int v : tree[u]){
            if(v == p) continue;
            ret[u] += self(self, v, u);
        }
        return ret[u];
    };
    rec(rec, r, -1);
    return ret;
}