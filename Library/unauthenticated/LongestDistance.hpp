/**
 * @file LongestDistance.hpp
 * @author log K (lX57)
 * @brief Longest Distance - DAGにおける最長距離
 * @version 1.0
 * @date 2024-02-11
 */

#include "GraphTemplate.hpp"

template<typename WeightType>
vector<WeightType> longestdistance(Graph<WeightType> &G, WeightType INF, Vertex start = -1, WeightType init = 0){
    vector<WeightType> dp(G.size(), INF);
    if(start == -1){
        for(auto v : G.source()) dp[v] = init;
    }
    else dp[start] = init;
    for(int i : G.topological_sort()){
        if(dp[i] == INF) continue;
        for(auto &e : G[i]){
            dp[e.to] = max(dp[e.to], dp[i] + e.cost);
        }
    }
    return dp;
}