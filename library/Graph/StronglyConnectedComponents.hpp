#pragma once

#include <bits/stdc++.h>
#include "VGraph.hpp"
using namespace std;

/**
 * @brief StronglyConnectedComponents
 */

/**
 * @brief  強連結成分分解を行う。
 */
template<typename T>
struct StronglyConnectedComponents{
    VGraph<T> &G, rG;
    vector<int> belong; // 頂点がどの強連結成分に所属するか
    vector<vector<int>> sc; // 各強連結成分に所属する頂点

    private:
    vector<int> order, visited;
    vector<int> tmp;

    void dfs(int v){
        visited[v] = 1;
        for(auto &e : G.vertex[v]){
            if(visited[e.to] == 0) dfs(e.to);
        }
        order.push_back(v);
    }

    void rdfs(int v, int k){
        visited[v] = 0;
        belong[v] = k;
        tmp.push_back(v);
        for(auto &e : rG.vertex[v]){
            if(visited[e.to] == 1) rdfs(e.to, k);
        }
    }

    public:
    StronglyConnectedComponents(VGraph<T> &G) : G(G){
        rG = G.reverse();
        visited.resize(G.sz, 0);
        belong.resize(G.sz, -1);
        for(int i = 0; i < G.sz; ++i){
            if(visited[i] == 0) dfs(i);
        }
        int k = 0;
        for(int i = order.size() - 1; i >= 0; --i){
            if(visited[order[i]] == 1){
                rdfs(order[i], k++);
                sc.push_back(tmp);
                tmp.clear();
            }
        }
    }

    /**
     * @brief  2つの頂点が同じ強連結成分に所属するかを判定する。
     * @param  u: 判定したい頂点u
     * @param  v: 判定したい頂点v
     * @retval 同じ強連結成分に所属するならtrue、そうでなければfalse
     */
    bool same(int u, int v){
        return belong[u] == belong[v];
    }
};