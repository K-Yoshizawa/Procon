#pragma once

#include "../Graph/Graph.hpp"

/**
 * @brief 木 `tree` の各頂点の深さを求める。
 * @note 根の頂点は深さ 0 である。
 * @note Verify : https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/7/ALDS1_7_A
 * @param tree 木
 * @param root 根の頂点番号 (default = 0)
 * @return vector<int> 各頂点の深さ
 */
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