#pragma once

/**
 * @brief Lowest Common Ancestor - 最小共通祖先
 */

#include "../Graph/GraphTemplate.hpp"

using namespace std;

template<typename CostType>
struct LowestCommonAncestor{
    private:
    Graph<CostType> &G;
    int sz, LOG;
    vector<int> depth;
    vector<vector<Vertex>> parent;

    void dfs(Vertex v, Vertex p, int d){
        parent[0][v] = p;
        depth[v] = d;
        for(auto &e : G.get_edges(v)){
            if(e.to != p) dfs(e.to, v, d + 1);
        }
    }

    public:
    LowestCommonAncestor(Graph<CostType> &G,Vertex Root) : G(G), sz(G.size()), LOG(32){
        depth.resize(sz);
        parent.resize(LOG, vector<Vertex>(sz, -1));
        dfs(Root, -1, 0);
        for(int k = 0; k + 1 < LOG; ++k){
            for(int v = 0; v < sz; ++v){
                if(parent[k][v] < 0) parent[k + 1][v] = -1;
                else parent[k + 1][v] = parent[k][parent[k][v]];
            }
        }
    }

    Vertex query(Vertex u, Vertex v){
        if(depth[u] > depth[v]) swap(u, v);
        for(int k = 0; k < LOG; ++k){
            if((depth[v] - depth[u]) >> k & 1){
                v = parent[k][v];
            }
        }
        if(u == v) return u;
        for(int k = LOG - 1; k >= 0; --k){
            if(parent[k][u] != parent[k][v]){
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }
};