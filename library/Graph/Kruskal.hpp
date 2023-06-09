#pragma once

/**
 * @brief Kruskal - 最小全域木
 */

#include <bits/stdc++.h>

#include "GraphTemplate.hpp"
#include "../DataStructure/UnionFind.hpp"

using namespace std;

template<typename CostType>
struct Kruskal{
    int V;
    vector<EdgeNum> MST;
    CostType Cost;

    Kruskal(Graph<CostType> &G){
        V = G.size();
        UnionFind uf(V);
    
        vector<pair<CostType, EdgeNum>> EL;
        for(int i = 0; i < G.edges.size(); ++i){
            EL.emplace_back(G.edges[i].cost, i);
        }
        sort(EL.begin(), EL.end());

        Cost = 0;
        for(auto &x : EL){
            auto e = G.get_edge(x.second);
            if(!uf.same(e.from, e.to)){
                uf.unite(e.from, e.to);
                Cost += x.first;
                MST.push_back(x.second);
            }
        }
    }
};