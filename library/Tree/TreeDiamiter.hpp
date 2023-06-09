#pragma once

/**
 * @brief Tree Diamiter - 木の直径
 */

#include "../Graph/GraphTemplate.hpp"

template<typename CostType>
struct TreeDiamiter{
    private:
    Graph<CostType> &G;
    vector<CostType> dist;

    void bfs(Vertex s){
        queue<Vertex> que;
        dist.assign(G.size(), G.INF);
        dist[s] = 0;
        que.push(s);
        while(!que.empty()){
            Vertex v = que.front();
            que.pop();
            for(EdgeNum &i : G.connect[v]){
                Vertex u = G.edges[i].to;
                CostType w = G.edges[i].cost;
                if(dist[v] + w < dist[u]){
                    dist[u] = dist[v] + w;
                    que.push(u);
                }
            }
        }
    }

    public:
    pair<Vertex, Vertex> EdgeVertex;
    CostType diamiter;

    TreeDiamiter(Graph<CostType> &G) : G(G), dist(G.size()){
        bfs(0);
        int v = 0;
        CostType d = 0;
        for(int i = 0; i < G.size(); ++i){
            if(dist[i] < d){
                v = i, d = dist[i];
            }
        }
        EdgeVertex.first = v;
        bfs(v);
        v = 0, d = 0;
        for(int i = 0; i < G.size(); ++i){
            if(dist[i] < d){
                v = i, d = dist[i];
            }
        }
        EdgeVertex.second = v;
        diamiter = d;
    }
};