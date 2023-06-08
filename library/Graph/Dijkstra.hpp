#pragma once

/**
 * @brief 単一始点最短距離（ダイクストラ法） - Dijkstra
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

    public:
    vector<CostType> dist;
    CostType INF;

    Dijkstra(Graph<CostType> &G) : G(G), dist(G.size()), INF(numeric_limits<CostType>::max()), prev_vertex(G.size()){}

    /**
     * @brief  頂点sを始点としてダイクストラ法を適用する。
     * @param  s: 始点となる頂点s
     * @note   求められた最短距離はdistに格納される。
     */
    void build(int s){
        dist.assign(G.size(), INF);
        prev_vertex.assign(G.size(), -1);
        using p = pair<CostType, Vertex>;
        priority_queue<p, vector<p>, greater<p>> que;
        que.emplace(0, s);
        dist[s] = 0;
        while(!que.empty()){
            auto [d, v] = que.top();
            que.pop();
            if(dist[v] < d) continue;
            for(auto &e : G.get_edges(v)){
                if(d + e.cost < dist[e.to]){
                    dist[e.to] = d + e.cost;
                    prev_vertex[e.to] = v;
                    que.emplace(d + e.cost, e.to);
                }
            }
        }
    }

    /**
     * @brief  頂点sから頂点tへの最短経路を取得する
     * @attention 予めbuildで最短距離を求める必要がある。
     * @param  t: 終点となる頂点t
     * @retval 最短経路
     */
    vector<int> restore(int t){
        vector<int> ret;
        int v = t;
        while(v != -1){
            ret.push_back(v);
            v = prev_vertex[v];
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};