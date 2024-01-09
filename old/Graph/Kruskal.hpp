/**
 * @file Kruskal.hpp
 * @author log K (lX57)
 * @brief Kruskal - 最小全域木
 * @version 2.0
 * @date 2023-11-01
 */

#include "GraphTemplate.hpp"
#include "../DataStructure/UnionFind.hpp"

template<typename CostType>
struct Kruskal{
    private:
    Graph<CostType> &G;
    vector<EdgeID> __RemainEdge;
    CostType __Cost;

    public:
    Kruskal(Graph<CostType> &G) : G(G), __Cost(0){
        UnionFind uf(G.vsize());
        auto es = G.get_edgeset();
        vector<EdgeID> eid(G.esize());
        iota(eid.begin(), eid.end(), 0);
        sort(eid.begin(), eid.end(), [&](EdgeID l, EdgeID r){return es[l].cost < es[r].cost;});
        for(EdgeID i : eid){
            if(uf.same(es[i].src, es[i].to)) continue;
            uf.unite(es[i].src, es[i].to);
            __RemainEdge.push_back(i);
            __Cost += es[i].cost;
        }
    }

    CostType get(){
        return __Cost;
    }
};