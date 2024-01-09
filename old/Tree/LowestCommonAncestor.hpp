/**
 * @file LowestCommonAncestor.hpp
 * @author log K (lX57)
 * @brief Lowest Common Ancestor - 最小共通祖先
 * @version 2.0
 * @date 2023-10-04
 */

#include "../Graph/GraphTemplate.hpp"

template<typename CostType>
struct LowestCommonAncestor{
    private:
    Graph<CostType> &G;
    int __Height;
    vector<int> __Depth;
    vector<vector<Vertex>> __Parent;

    void __dfs(Vertex v, Vertex p, int d){
        __Parent[0][v] = p;
        __Depth[v] = d;
        for(auto &e : G.get_incident(v)){
            if(e.to != p) __dfs(e.to, v, d + 1);
        }
    }

    public:
    LowestCommonAncestor(Graph<CostType> &G, Vertex Root) : G(G), __Height(32){
        __Depth.resize(G.vsize());
        __Parent.resize(__Height, vector<Vertex>(G.vsize(), -1));
        __dfs(Root, -1, 0);
        for(int k = 0; k + 1 < __Height; ++k){
            for(Vertex v = 0; v < G.vsize(); ++v){
                if(__Parent[k][v] < 0) __Parent[k + 1][v] = -1;
                else __Parent[k + 1][v] = __Parent[k][__Parent[k][v]];
            }
        }
    }

    Vertex get(Vertex u, Vertex v){
        if(__Depth[u] > __Depth[v]) swap(u, v);
        for(int k = 0; k < __Height; ++k){
            if((__Depth[v] - __Depth[u]) >> k & 1){
                v = __Parent[k][v];
            }
        }
        if(u == v) return u;
        for(int k = __Height - 1; k >= 0; --k){
            if(__Parent[k][u] != __Parent[k][v]){
                u = __Parent[k][u];
                v = __Parent[k][v];
            }
        }
        return __Parent[0][u];
    }
};