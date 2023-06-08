#pragma once

#include <bits/stdc++.h>
using namespace std;

#include "VGraph.hpp"

/**
 * @brief Cycle Detection
 */

/**
 * @brief 有向グラフの閉路検出を行う。
 */
template<typename T>
struct CycleDetection{
    vector<vector<int>> cycle;
    
    private:
    VGraph<T> &G;
    vector<int> visited, history;
    vector<int> belong;
    vector<int> tmp;

    void dfs(int v){
        visited[v] = 1;
        history.push_back(v);
        for(auto &e : G.vertex[v]){
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
    CycleDetection(VGraph<T> &G) : G(G), visited(G.sz, 0), belong(G.sz, -1){
        assert(G.directed == true);
        for(int i = 0; i < G.sz; ++i){
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