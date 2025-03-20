#pragma once

#include "Graph.hpp"

template<typename CostType>
vector<Edge<CostType>> ConvertEdgeSet(const Graph<CostType> &G){
    vector<Edge<CostType>> ret;
    vector<bool> check(G.EdgeSize(), false);
    int n = G.VertexSize();
    for(int u = 0; u < n; ++u){
        for(const Edge<CostType> &e : G[u]){
            if(check[e.idx]) continue;
            check[e.idx] = true;
            ret.push_back(e);
        }
    }
    return ret;
}