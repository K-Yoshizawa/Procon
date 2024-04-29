/**
 * @file Kruskal.hpp
 * @brief Kruskal - 最小全域木
 * @version 3.1
 * @date 2024-02-11
 */

#include "GraphTemplate.hpp"
#include "../DataStructure/UnionFind.hpp"

template<typename CostType>
struct Kruskal{
    private:
    Graph<CostType> &G;
    vector<int> used_;
    CostType ans_;

    public:
    Kruskal(Graph<CostType> &G) : G(G){
        ans_ = 0;
        UnionFind uf(G.size());
        auto es = G.edge_set();
        for(auto &e : es){
            int i = e.id;
            if(uf.same(e.from, e.to)) continue;
            uf.unite(e.from, e.to);
            used_.push_back(i);
            ans_ += e.cost;
        }
    }

    vector<int> &get(){
        return used_;
    }

    CostType val(){
        return ans_;
    }
};