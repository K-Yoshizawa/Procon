#pragma once

/**
 * @brief 単一始点最短距離（ベルマンフォード法） - Bellman Ford
 */

#include <bits/stdc++.h>
using namespace std;

#include "GraphTemplate.hpp"

template<typename CostType>
vector<CostType> BellmanFord(Graph<CostType> &G, int s){
    const CostType INF = numeric_limits<CostType>::max();
    vector<CostType> ret(G.size(), INF);
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
            if(ret[from] == INF) continue;
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