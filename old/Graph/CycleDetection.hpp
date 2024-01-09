#pragma once

/**
 * @brief Cycle Detection (Directed) - 閉路検出（有向グラフ）
 */

#include <bits/stdc++.h>
using namespace std;

#include "GraphTemplate.hpp"

/**
 * @brief 有向グラフの閉路検出を行う。
 */
template<typename CostType>
struct CycleDetection{
    vector<vector<Vertex>> cycle;
    
    private:
    Graph<CostType> &G;
    vector<Vertex> visited, history;
    vector<Vertex> belong;
    vector<Vertex> tmp;

    void dfs(int v){
        visited[v] = 1;
        history.push_back(v);
        for(auto &e : G.get_edges(v)){
            if(visited[e.to] == 2) continue;
            if(visited[e.to] == 1){
                for(int i = history.size() - 1; ; --i){
                    tmp.push_back(history[i]);
                    belong[history[i]] = cycle.size();
                    if(history[i] == e.to) break;
                }
                cycle.push_back(tmp);
                tmp.clear();
            }
            else{
                dfs(e.to);
            }
        }
        history.pop_back();
        visited[v] = 2;
    }

    public:
    CycleDetection(Graph<CostType> &G) : G(G), visited(G.size(), 0), belong(G.size(), -1){
        assert(G.directed());
        for(int i = 0; i < G.size(); ++i){
            if(!visited[i]) dfs(i);
        }
    }

    /**
     * @brief グラフGが閉路を持つかを判定する。
     */
    bool exist(){
        return cycle.size() > 0;
    }
};