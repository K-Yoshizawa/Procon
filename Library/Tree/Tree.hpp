#pragma once

#include "../Graph/Graph.hpp"

template<typename CostType = int32_t>
Graph<CostType> InputTree(int N, int padding = -1, bool weighted = false){
    Graph<CostType> G(N);
    for(int i = 0; i < N - 1; ++i){
        Vertex u, v; CostType w = 1;
        cin >> u >> v, u += padding, v += padding;
        if(weighted) cin >> w;
        G.AddUndirectedEdge(u, v, w);
    }
    return G;
}

template<typename CostType = int32_t>
Graph<CostType> InputRootedTreeChild(int N, int padding = -1){
    Graph<CostType> G(N);
    for(Vertex u = 0; u < N; ++u){
        int k; cin >> k;
        for(int i = 0; i < k; ++i){
            Vertex v; cin >> v, v += padding;
            G.AddUndirectedEdge(u, v);
        }
    }
    return G;
}

template<typename CostType = int32_t>
Graph<CostType> InputRootedTreeParent(int N, int padding = -1){
    Graph<CostType> G(N);
    for(Vertex u = 1; u < N; ++u){
        Vertex v; cin >> v, v += padding;
        G.AddUndirectedEdge(u, v);
    }
    return G;
}

template<typename CostType>
vector<int> CalculateTreeParent(Graph<CostType> &T, Vertex r = 0){
    int n = T.VertexSize();
    vector<int> ret(n, -1);
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

template<typename CostType>
vector<int> CalculateTreeDepth(Graph<CostType> &T, Vertex r = 0){
    int n = T.VertexSize();
    vector<int> ret(n, 0);
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

template<typename CostType>
vector<CostType> CalculateTreeDistance(Graph<CostType> &T, Vertex r = 0){
    int n = T.VertexSize();
    vector<CostType> ret(n, CostType(INF));
    auto rec = [&](auto &self, Vertex u) -> void {
        for(const Edge<CostType> &e : T[u]){
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

template<typename CostType>
vector<int> CalculateSubtreeSize(Graph<CostType> &tree, Vertex r = 0){
    int n = tree.VertexSize();
    vector<int> ret(n, 1);
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

// /**
//  * @brief 各頂点を行きかけ順に並べたときに何番目に相当するかの配列を求める。
//  * @param tree 木
//  * @return vector<int> 各頂点が行きかけ順で何番目になるか (0-index)
//  */
// template<typename CostType>
// vector<int> CalculatePreOrder(RootedTree<CostType> &tree){
//     Vertex root = tree.get_root();
//     int V = tree.get_vertex_size(), time_stamp = 0;
//     vector<int> ret(V, -1);
//     auto rec = [&](auto self, Vertex v) -> void {
//         ret[v] = time_stamp++;
//         for(Vertex u : tree.get_child()){
//             self(self, u);
//         }
//     };
//     rec(rec, root);
//     return ret;
// }