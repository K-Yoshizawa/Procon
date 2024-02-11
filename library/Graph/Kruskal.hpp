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
    vector<int> m_used;
    CostType m_ans;

    public:
    Kruskal(Graph<CostType> &G) : G(G){
        m_ans = 0;
        UnionFind uf(G.size());
        auto es = G.edge_set();
        for(auto &e : es){
            int i = e.id;
            if(uf.same(e.from, e.to)) continue;
            uf.unite(e.from, e.to);
            m_used.push_back(i);
            m_ans += e.cost;
        }
    }

    vector<int> &get(){
        return m_used;
    }

    CostType val(){
        return m_ans;
    }
};