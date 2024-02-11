/**
 * @file BellmanFord.hpp
 * @brief BellmanFord - ベルマンフォード法
 * @version 3.1
 * @date 2024-02-11
 */

#include "GraphTemplate.hpp"

template<typename CostType>
vector<CostType> BellmanFord(Graph<CostType> &G, Vertex s){
    vector<CostType> ret(G.size(), G.INF);
    ret[s] = 0;
    int updatecount = 0;
    auto es = G.edge_set();
    while(1){
        if(updatecount == G.size()){
            return vector<CostType>{};
        }
        bool update = false;
        for(auto &e : es){
            if(ret[e.from] == G.INF) continue;
            if(ret[e.to] > ret[e.from] + e.cost){
                ret[e.to] = ret[e.from] + e.cost;
                update = true;
            }
        }
        if(!update) break;
        ++updatecount;
    }
    return ret;
}