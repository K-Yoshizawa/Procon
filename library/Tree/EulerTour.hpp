#pragma once

/**
 * @brief Euler Tour - オイラーツアー
 */

#include "../Graph/GraphTemplate.hpp"
#include "../DataStructure/BinaryIndexedTree.hpp"

template<typename CostType>
struct EulerTour{
    private:
    int sz, k;
    using Tour = int;
    Graph<CostType> &G;
    vector<Tour> arrival, departure; // 頂点iに訪れた時間 / 頂点iから去る時間 : BITに乗せることを想定しているため、クエリ処理を簡易にするために1-indexで記録する
    BinaryIndexedTree<CostType> BIT;
    vector<pair<Vertex, EdgeNum>> relation;

    void dfs1(int v, int pre){
        arrival[v] = k++;
        for(auto &e : G.get_edges(v)){
            if(e.to == pre) continue;
            dfs1(e.to, v);
        }
        departure[v] = k++;
    }

    void dfs2(int v, int pre, CostType value){
        BIT.add(arrival[v], value);
        for(auto &e : G.get_edges(v)){
            if(e.to == pre) continue;
            dfs2(e.to, v, e.cost);
        }
        BIT.add(departure[v], -value);
    }

    public:
    /**
     * @brief 頂点rootを根とした木Gでオイラーツアーを構築する。
     * @attention Gが木でない場合の動作は未定義
     * @param G 木
     * @param root 根 (option, default = 0)
     */
    EulerTour(Graph<CostType> &G, Vertex root = 0) : G(G), sz(G.size()), BIT(G.size() * 2), k(1){
        arrival.resize(sz, -1);
        departure.resize(sz, -1);
        dfs1(root, -1);
        dfs2(0, -1, 0);
        relation = G.get_parent(root);
    }

    /**
     * @brief 根から頂点vへの距離をBITを用いて取得する。
     * @param v 取得したい頂点番号v
     * @return CostType 根から頂点vへの距離
     */
    CostType query(Vertex v){
        return BIT.sum(arrival[v]);
    }

    /**
     * @brief 頂点childとその親を結ぶ辺の重みをx増加させる一点更新クエリ
     * @param child 子の頂点を表す頂点番号
     * @param x 増加させる重み
     */
    void add(Vertex child, CostType x){
        auto [parent, ed] = relation[child];
        G.edges[ed].cost += x;
        G.edges[G.rev[ed]].cost += x;
        BIT.add(arrival[child], x);
        BIT.add(departure[child], -x);
    }

    void update(Vertex child, CostType x){
        auto [parent, ed] = relation[child];
        CostType diff = x - G.edges[ed].cost;
        G.edges[ed].cost += diff;
        G.edges[G.rev[ed]].cost += diff;
        BIT.add(arrival[child], diff);
        BIT.add(departure[child], -diff);
    }
};