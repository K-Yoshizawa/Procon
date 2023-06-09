#pragma once

/**
 * @brief Warshall-Floyd - 全点間最短距離
 */

#include <bits/stdc++.h>

#include "GraphTemplate.hpp"

using namespace std;

template<typename CostType>
struct WarshallFloyd{
    bool negative;
    vector<vector<CostType>> dist;

    WarshallFloyd(Graph<CostType> &G){
        int V = G.size();
        
        dist.resize(V, vector<CostType>(V, G.INF));
        for(int i = 0; i < V; ++i) dist[i][i] = 0;
        for(auto &e : G.edges){
            dist[e.from][e.to] = e.cost;
        }

        for(int k = 0; k < V; ++k){
            for(int i = 0; i < V; ++i){
                for(int j = 0; j < V; ++j){
                    if(dist[i][k] == G.INF || dist[k][j] == G.INF) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        negative = false;
        for(int i = 0; i < V; ++i) negative |= dist[i][i] < 0;
    }
};