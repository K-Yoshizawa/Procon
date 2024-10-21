/**
 * @file TwoEdgeConnectedComponents.hpp
 * @brief Two-Edge-Connected Components - 二辺連結成分分解
 * @version 1.0
 * @date 2024-10-21
 */

#include "LowLink.hpp"

template<typename CostType>
class TwoEdgeConnectedComponents{
    public:
    /**
     * @brief グラフから二辺連結成分分解を行う。
     */
    TwoEdgeConnectedComponents(Graph<CostType> &graph) : G(graph){
        LowLink<CostType> lowlink(G);
        vector<bool> is_bridge(G.get_edge_size(), false);
        for(Edge<CostType> &es : lowlink.get_bridge()){
            is_bridge[es.id] = true;
        }
        vector<bool> visited(G.get_vertex_size(), false);
        queue<Vertex> que;
        for(int s = 0; s < G.get_vertex_size(); ++s){
            if(visited[s]) continue;
            que.push(s);
            visited[s] = true;
            components_.push_back({});
            while(que.size()){
                Vertex v = que.front();
                components_.back().push_back(v);
                que.pop();
                for(Edge<CostType> &es : G[v]){
                    if(is_bridge[es.id]) continue;
                    if(visited[es.to]) continue;
                    que.push(es.to);
                    visited[es.to] = true;
                }
            }
        }
    }

    /**
     * @brief すべての二辺連結成分とそれに含まれるすべての頂点を列挙する。
     */
    vector<vector<Vertex>> &get_components(){
        return components_;
    }
    
    private:
    Graph<CostType> &G;

    vector<vector<Vertex>> components_;
};