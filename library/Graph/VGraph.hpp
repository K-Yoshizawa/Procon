#pragma once

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Vertex Graph
 */

/**
 * @brief グラフの辺
 */
template<typename T>
struct Edge{
    int from, to;
    T cost;

    Edge(int from, int to, T cost) : from(from), to(to), cost(cost){}
};

/**
 * @brief 頂点集合で管理するグラフ
 */
template<typename T>
struct VGraph{
    int sz; // グラフの頂点数
    bool directed; // 有向グラフか
    vector<vector<Edge<T>>> vertex; // 頂点集合
    vector<int> indegree, outdegree; // 入次数、出次数

    VGraph(int size, bool directed = false) : sz(size), vertex(size), indegree(size, 0), outdegree(size, 0), directed(directed){}
    VGraph() = default;

    /**
     * @brief 無向グラフの場合は頂点sと頂点tを結ぶ無向辺、有向グラフの場合は頂点sから頂点tへの有向辺を追加する。
     * 
     * @param s 頂点s (0-index)
     * @param t 頂点t (0-index)
     * @param w 重み (省略可、省略時は1)
     */
    void add(int s, int t, T w = 1){
        vertex[s].push_back(Edge<T>(s, t, w));
        ++outdegree[s];
        ++indegree[t];
        if(!directed){
            vertex[t].push_back(Edge<T>(t, s, w));
            ++indegree[s];
            ++outdegree[t];
        }
    }

    /**
     * @brief 逆辺を張ったグラフを返す。
     * @attention グラフが有向グラフでなければならない。
     * @return VGraph<T> 逆辺を張ったグラフ
     */
    VGraph<T> reverse(){
        assert(directed == true);
        VGraph<T> ret(sz, true);
        for(int s = 0; s < sz; ++s){
            for(auto &e : vertex[s]){
                ret.add(e.to, s, e.cost);
            }
        }
        return ret;
    }
};