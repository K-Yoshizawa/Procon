/**
 * @file BellmanFord.hpp
 * @author log_K (lX57)
 * @brief BellmanFord - 単一始点最短距離
 * @version 2.1
 * @date 2023-10-02
 */

#include "GraphTemplate.hpp"

template<typename CostType>
vector<CostType> BellmanFord(Graph<CostType> &G, Vertex Start){
    vector<CostType> ret(G.vsize(), G.INF);
    ret[Start] = 0;
    int updatecount = 0;
    while(1){
        if(updatecount == G.vsize()){
            return vector<CostType>{};
        }
        bool update = false;
        for(auto e : G.get_edgeset()){
            if(ret[e.src] == G.INF) continue;
            if(ret[e.to] > ret[e.src] + e.cost){
                ret[e.to] = ret[e.src] + e.cost;
                update = true;
            }
        }
        if(!update) break;
        ++updatecount;
    }
    return ret;
}