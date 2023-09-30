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
    private:
    Graph<CostType> &G;
    vector<int> __used;

    CostType __dfs(Vertex pos, Vertex goal, CostType F){
        if(pos == goal) return F;
        __used[pos] = 1;
        for(auto e : G.get_incident(pos)){
            if(e.cap == 0 || __used[e.to]) continue;
            CostType flow = __dfs(e.to, goal, min(F, e.cap));
            if(flow >= 1){
                G.update_flow(e.from, e.ID, flow);
                return flow;
            }
        }
        return 0;
    }

    public:
    FordFulkerson(Graph<CostType> &G) : G(G), __used(G.vsize(), 0){}

    CostType solve(Vertex Source, Vertex Sink){
        CostType ans = 0;
        while(1){
            __used.assign(G.vsize(), 0);
            CostType F = __dfs(Source, Sink, G.INF);
            if(F == 0) break;
            ans += F;
        }
        return ans;
    }

    vector<Edge<CostType>> get_flow(){
        return G.get_flow();
    }
};