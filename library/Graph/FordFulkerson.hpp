#pragma once

/**
 * @brief Ford-Fulkerson - 最大フロー
 */

#include <bits/stdc++.h>

#include "GraphTemplate.hpp"

using namespace std;

template<typename CostType>
struct FordFulkerson{
    int E;
    Graph<CostType> &G;
    vector<EdgeNum> rev;

    private:
    vector<int> used;

    CostType dfs(Vertex pos, Vertex goal, CostType F){
        if(pos == goal) return F;
        used[pos] = 1;
        for(EdgeNum &i : G.connect[pos]){
            if(G.edges[i].cost == 0) continue;
            if(used[G.edges[i].to]) continue;
            CostType flow = dfs(G.edges[i].to, goal, min(F, G.edges[i].cost));
            if(flow >= 1){
                G.edges[i].cost -= flow;
                G.edges[rev[i]].cost += flow;
                return flow;
            }
        }
        return 0;
    }

    public:
    FordFulkerson(Graph<CostType> &G) : G(G), used(G.size(), 0){
        E = G.edges.size();
        rev.resize(2 * E);
        for(int i = 0; i < E; ++i){
            rev[i] = i + E;
            rev[i + E] = i;
            Edge<CostType> e = G.get_edge(i);
            G.add(e.to, e.from, 0);
        }
    }

    /**
     * @brief  頂点sから頂点tへの最大流を求める。
     * @param  s: 始点の頂点s
     * @param  t: 終点の頂点t
     * @retval 最大流
     */
    CostType query(Vertex s, Vertex t){
        CostType ret = 0;
        while(1){
            used.assign(G.size(), 0);
            CostType F = dfs(s, t, G.INF);
            if(F == 0) break;
            ret += F;
        }
        return ret;
    }
};