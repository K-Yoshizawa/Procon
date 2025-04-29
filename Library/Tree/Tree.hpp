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

// /**
//  * @brief 木の根から各頂点への辺の重みの累積和を計算する。
//  * @param tree 木
//  * @return vector<CostType> 根から各頂点への重みの累積和
//  */
// template<typename CostType>
// vector<CostType> CalculateTreeCumlativeSum(RootedTree<CostType> &tree){
//     Vertex root = tree.get_root();
//     int V = tree.get_vertex_size();
//     vector<CostType> ret(V, 0);
//     auto rec = [&](auto self, Vertex v, CostType s) -> void {
//         ret[v] = s + tree.get_cost(v);
//         for(Vertex u : tree.get_child(v)){
//             self(self, u, ret[v]);
//         }
//     };
//     rec(rec, root, 0);
//     return ret;
// }

// /**
//  * @brief 各頂点を根とする部分木のサイズを求める。
//  * @param tree 木
//  * @return vector<int> 各頂点を根とする部分木のサイズ
//  */
// template<typename CostType>
// vector<int> CalculateSubtreeSize(RootedTree<CostType> &tree){
//     Vertex root = tree.get_root();
//     int V = tree.get_vertex_size();
//     vector<int> ret(V, 1);
//     auto rec = [&](auto self, Vertex v) -> int {
//         for(Vertex u : tree.get_child(v)){
//             ret[v] += self(self, u);
//         }
//         return ret[v];
//     };
//     rec(rec, root);
//     return ret;
// }

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