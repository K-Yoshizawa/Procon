/**
 * @file FordFulkerson.hpp
 * @author log K (lX57)
 * @brief Ford-Fulkerson - 最大流
 * @version 2.0
 * @date 2023-09-01
 */

#include "GraphTemplate.hpp"

template<typename CostType>
struct FordFulkerson{
    public:
    map<pair<Vertex, Vertex>, CostType> flew_list;

    private:
    Graph<CostType> &G;
    vector<int> used;

    CostType dfs(Vertex pos, Vertex goal, CostType F){
        if(pos == goal) return F;
        used[pos] = 1;
        for(auto [eid, rev] : G.get_raw_incident(pos)){
            auto e = G.get_edge(eid, rev);
            if(e.cap == 0 || used[e.to]) continue;
            CostType flow = dfs(e.to, goal, min(F, e.cap));
            if(flow >= 1){
                G.update_flow(eid, rev, flow);
                flew_list[{pos, e.to}] += flow;
                flew_list[{e.to, pos}] -= flow;
                return flow;
            }
        }
        return 0;
    }

    public:
    FordFulkerson(Graph<CostType> &G) : G(G), used(G.vsize(), 0), flew_list(G.vsize()){}

    CostType solve(Vertex Source, Vertex Sink){
        CostType ans = 0;
        flew_list.clear();
        while(1){
            used.assign(G.vsize(), 0);
            CostType F = dfs(Source, Sink, G.INF);
            if(F == 0) break;
            ans += F;
        }
        return ans;
    }

    vector<pair<Vertex, CostType>> flow_to(Vertex from){
        vector<pair<Vertex, CostType>> ret;
        for(auto [e, val] : flew_list){
            if(e.first == from && val > 0) ret.push_back({to, val});
        }
        return ret;
    }
};