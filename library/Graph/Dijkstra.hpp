#pragma once

/**
 * @brief Dijkstra - 単一始点最短距離（ダイクストラ法）
 */

#include <bits/stdc++.h>
#include "GraphTemplate.hpp"
using namespace std;

/**
 * @brief  ダイクストラ法で最短距離を求める。
 * @attention グラフに負の重みの辺がない必要がある。
 */
template<typename CostType>
struct Dijkstra{
    private:
    Graph<CostType> &G;
    vector<Vertex> prev_vertex;
    vector<EdgeNum> prev_edge;

    public:
    vector<CostType> dist;

    Dijkstra(Graph<CostType> &G) : G(G), dist(G.size()), prev_vertex(G.size()), prev_edge(G.size()){}

    /**
     * @brief  頂点sを始点としてダイクストラ法を適用する。
     * @param  s: 始点となる頂点s
     * @note   求められた最短距離はdistに格納される。
     */
    void build(int s){
        dist.assign(G.size(), G.INF);
        prev_vertex.assign(G.size(), -1);
        prev_edge.assign(G.size(), -1);
        using p = pair<CostType, Vertex>;
        priority_queue<p, vector<p>, greater<p>> que;
        que.emplace(0, s);
        dist[s] = 0;
        while(!que.empty()){
            auto [d, v] = que.top();
            que.pop();
            if(dist[v] < d) continue;
            for(auto &eidx : G.get_list(v)){
                auto e = G.get_edge(eidx);
                if(d + e.cost < dist[e.to]){
                    dist[e.to] = d + e.cost;
                    prev_vertex[e.to] = v;
                    prev_edge[e.to] = eidx;
                    que.emplace(d + e.cost, e.to);
                }
            }
        }
    }

    /**
     * @brief  頂点sから頂点tへの最短経路を取得する
     * @attention 予めbuildで最短距離を求める必要がある。
     * @param  t: 終点となる頂点t
     * @param  isEdge: 頂点番号の代わりに辺番号を取得する(opt default = false)
     * @retval 最短経路の頂点番号 or 辺番号
     */
    vector<int> restore(int t, bool isEdge = false){
        vector<int> ret;
        int v = t;
        while(v != -1){
            if(!isEdge) ret.push_back(v);
            else if(prev_edge[v] != -1) ret.push_back(prev_edge[v]);
            v = prev_vertex[v];
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};