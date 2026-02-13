#pragma once

#include "Graph.hpp"

template<typename WeightType>
class LowLink{
    public:
    LowLink(Graph<WeightType> &graph) : G(graph), V(graph.VertexSize()), ord_(V, -1), low_(V, -1), in_(V), out_(V){
        for(int i = 0, k = 0, t = 0; i < V; ++i){
            if(ord_[i] == -1){
                k = dfs(i, -1, k, t);
            }
        }
    }

    vector<Vertex> &ArticulationPoint(){
        return articulation_point_;
    }

    vector<pair<Vertex, Vertex>> &Bridge(){
        return bridge_;
    }

    pair<int, int> EulerTour(const Vertex v) const {
        return {in_[v], out_[v]};
    }

    private:
    Graph<WeightType> &G;
    int V;
    vector<int> ord_, low_, in_, out_;
    vector<Vertex> articulation_point_;
    vector<pair<Vertex, Vertex>> bridge_;

    int dfs(Vertex v, int p, int k, int &t){
        in_[v] = t++;
        low_[v] = (ord_[v] = k++);
        int cnt = 0;
        bool is_articulation = false, second = false;
        for(int u : G[v]){
            if(ord_[u] == -1){
                ++cnt;
                k = dfs(u, v, k, t);
                low_[v] = min(low_[v], low_[u]);
                is_articulation |= (p != -1) && (low_[u] >= ord_[v]);
                if(ord_[v] < low_[u]){
                    bridge_.emplace_back(minmax(u, v));
                }
            }
            else if(u != p || second){
                low_[v] = min(low_[v], ord_[u]);
            }
            else{
                second = true;
            }
        }
        is_articulation |= (p == -1) && (cnt > 1);
        if(is_articulation) articulation_point_.emplace_back(v);
        out_[v] = t;
        return k;
    }
};