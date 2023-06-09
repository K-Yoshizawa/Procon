#pragma once

/**
 * @brief Bellman Ford - 単一始点最短距離（ベルマンフォード法）
 */

#include <bits/stdc++.h>
using namespace std;

#include "GraphTemplate.hpp"

template<typename CostType>
vector<CostType> BellmanFord(Graph<CostType> &G, int s){
    vector<CostType> ret(G.size(), G.INF);
    ret[s] = 0;
    int updatecount = 0;
    while(1){
        if(updatecount == G.size()){
            ret[s] = -1;
            return ret;
        }
        bool update = false;
        for(auto &e : G.edges){
            Vertex from = e.from, to = e.to;
            CostType cost = e.cost;
            if(ret[from] == G.INF) continue;
            if(ret[to] > ret[from] + cost){
                ret[to] = ret[from] + cost;
                update = true;
            }
        }
        if(!update) break;
        ++updatecount;
    }
    return ret;
}