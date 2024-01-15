/**
 * @file Kruskal.hpp
 * @brief Kruskal - 最小全域木
 * @version 3.0
 * @date 2024-01-14
 */

#include "GraphTemplate.hpp"
#include "../DataStructure/UnionFind.hpp"

template<typename CostType>
struct Kruskal{
    private:
    GraphE<CostType> &G;
    vector<int> m_used;
    CostType m_ans;

    public:
    Kruskal(GraphE<CostType> &G) : G(G){
        m_ans = 0;
        UnionFind uf(G.size());
        for(auto i : G.sort()){
            auto e = G[i];
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