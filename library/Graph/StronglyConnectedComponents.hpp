/**
 * @file StronglyConnectedComponents.hpp
 * @brief Strongly Connected Components - 強連結成分分解
 * @version 3.1
 * @date 2024-02-11
 */

#include "Graph.hpp"

template<typename CostType>
struct StronglyConnectedComponents{
    private:
    Graph<CostType> &G;
    Graph<CostType> rG;

    size_t V;

    int dfs1(Vertex v, Vertex p, vector<int> &label, int nex){
        label[v] = nex;
        int ret = 1;
        for(auto &e : G[v]){
            if(e.to == p || label_[e.to] != -1) continue;
            int used = dfs1(e.to, v, label, nex + ret);
            ret += used;
        }
        return ret;
    }

    // void dfs2(Vertex v, Vertex p, vector<int> &vis, )

    public:
    StronglyConnectedComponents(Graph<CostType> &G) : G(G), V(G.get_vertex_size()){
        rG = reverse(G);
        vector<int> label(V, -1);
        int nex = 0;
        vector<Vertex> vs(V);
        for(auto v : vs){
            if(label[v] == -1) nex += dfs1(v, -1, label, nex);
        }
        iota(vs.begin(), vs.end(), 0);
        sort(vs.begin(), vs.end(), [&](Vertex u, Vertex v){
            return label[u] > label[v];
        });
    }


};