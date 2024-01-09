/**
 * @file LongestDistance.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-01-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "GraphTemplate.hpp"

template<typename CostType>
vector<CostType> longestdistance(GraphV<CostType> &G, CostType INF, Vertex start = -1, CostType init = 0){
    vector<CostType> dp(G.size(), INF);
    if(start == -1){
        for(auto v : G.source()) dp[v] = init;
    }
    else dp[start] = init;
    for(int i : G.sort()){
        if(dp[i] == INF) continue;
        for(auto &e : G[i]){
            dp[e.to] = max(dp[e.to], dp[i] + e.cost);
        }
    }
    return dp;
}