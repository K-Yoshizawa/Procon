/**
 * @file Kruskal.hpp
 * @brief Kruskal - 最小全域木
 * @version 4.0
 * @date 2024-07-19
 */

#include "Graph.hpp"
#include "../DataStructure/UnionFind.hpp"

template<typename CostType, bool ReverseFlag = false>
struct Kruskal{
    private:
    Graph<CostType> &G;
    vector<int> remain_edge_id_;
    CostType minimum_cost_;

    public:
    /**
     * @brief グラフを基に最小全域木を構築する。
     * @param G_ 頂点数 V のグラフ
     */
    Kruskal(Graph<CostType> &G_) : G(G_){
        minimum_cost_ = 0;
        UnionFind uf(G.get_vertex_size());
        auto es = convert_to_edge_set(G);
        if(ReverseFlag) reverse(es.begin(), es.end());
        for(Edge<CostType> &e : es){
            int i = e.id;
            if(uf.same(e.from, e.to)) continue;
            uf.unite(e.from, e.to);
            remain_edge_id_.push_back(i);
            minimum_cost_ += e.cost;
        }
    }

    /**
     * @brief 最小全域木に含まれる辺番号を返す。
     * @note verify : https://judge.yosupo.jp/problem/minimum_spanning_tree
     * @return vector<int>& 辺番号のベクトル
     */
    vector<int> &get_edge_id(){
        return remain_edge_id_;
    }

    /**
     * @brief 最小全域木のコストを返す。
     * @note verify : https://judge.yosupo.jp/problem/minimum_spanning_tree
     * @return CostType 最小全域木のコスト
     */
    CostType get_value(){
        return minimum_cost_;
    }
};