#pragma once

#include "Graph.hpp"

template<typename WeightType>
vector<Edge<WeightType>> CycleDetection(Graph<WeightType> &G){
    int V = G.VertexSize();
    vector<Edge<WeightType>> history;
    vector<int> state(V, 0);
    vector<Edge<WeightType>> ret;
    bool detected = false;
    auto dfs = [&](auto &self, int v, int pre) -> void {
        state[v] = 1;
        for(const Edge<WeightType> &e : G[v]){
            if(e.idx == pre) continue;
            if(state[e.to] == 2) continue;
            else if(state[e.to] == 1){
                ret.push_back(e);
                for(int i = history.size() - 1; i >= 0 && history[i].to != e.to; --i){
                    ret.push_back(history[i]);
                }
                detected = true;
            }
            else{
                history.push_back(e);
                self(self, e.to, e.idx);
                history.pop_back();
            }
            if(detected) return;
        }
        state[v] = 2;
    };
    for(int v = 0; v < V && !detected; ++v){
        if(state[v] == 0) dfs(dfs, v, -1);
    }
    reverse(ret.begin(), ret.end());
    return ret;
}