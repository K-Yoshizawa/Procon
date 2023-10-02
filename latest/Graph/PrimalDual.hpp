/**
 * @file PrimalDual.hpp
 * @author log K (lX57)
 * @brief Primal Dual - 最小費用流
 * @version 1.1
 * @date 2023-10-02
 */

#include "FlowTemplate.hpp"
#include "Dijkstra.hpp"

template<typename CostType>
struct PrimalDual{
    private:
    Flow<CostType> &G;
    vector<CostType> Potential;

    public:
    PrimalDual(Flow<CostType> &G) : G(G), Potential(G.vsize()){}

    CostType solve(Vertex Start, Vertex Goal, CostType F){
        CostType ret = 0;
        Potential.assign(G.vsize(), 0);

        while(F > 0){
            Dijkstra<CostType> dk(G);
            dk.update_potential(Potential);
            vector<CostType> Dist = dk.all(Start);
            if(Dist[Goal] == G.INF) return -1;
            auto path = dk.restore_edge(Goal);
            CostType f = F;
            for(auto e : path){
                f = min(f, e.cap);
            }
            F -= f;
            ret += f * Dist[Goal];
            for(auto e : path){
                G.update(e.src, e.sidx, f);
            }
            for(int i = 0; i < Dist.size(); ++i){
                CostType RawDist = Dist[i] -= Potential[i] - Potential[Start];
                Potential[i] = min(Potential[i] + RawDist, G.INF);
            }
        }
        return ret;
    }
};