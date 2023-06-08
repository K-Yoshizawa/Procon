#pragma once

#include <bits/stdc++.h>
#include "VGraph.hpp"
using namespace std;

/**
 * @brief Dijkstra
 */

/**
 * @brief  ダイクストラ法で最短距離を求める。
 * @attention グラフに負の重みの辺がない必要がある。
 */
template<typename T>
struct Dijkstra{
    private:
    VGraph<T> &G;
    vector<int> prev_vertex;

    public:
    vector<T> dist;
    T INF;

    Dijkstra(VGraph<T> &G) : G(G), dist(G.sz), INF(numeric_limits<T>::max()), prev_vertex(G.sz){}

    /**
     * @brief  頂点sを始点としてダイクストラ法を適用する。
     * @param  s: 始点となる頂点s
     * @note   求められた最短距離はdistに格納される。
     */
    void build(int s){
        dist.assign(G.sz, INF);
        prev_vertex.assign(G.sz, -1);
        using p = pair<T, int>;
        priority_queue<p, vector<p>, greater<p>> que;
        que.emplace(0, s);
        dist[s] = 0;
        while(!que.empty()){
            auto [d, v] = que.top();
            que.pop();
            if(dist[v] < d) continue;
            for(auto &e : G.vertex[v]){
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