#pragma once

/**
 * @brief グラフテンプレート - Graph Template
 */

#include <bits/stdc++.h>
using namespace std;

using EdgeNum = int;
using Vertex = int;

/**
 * @brief グラフの辺
 */
template<typename CostType = int>
struct Edge{
    Vertex from, to;
    CostType cost;

    Edge(Vertex from, Vertex to, CostType cost) : from(from), to(to), cost(cost){}
};

/**
 * @brief グラフを表すクラス。
 * @note 辺集合によって実現している。
 * @tparam CostType 辺の重みの型。
 */
template<typename CostType = int>
class Graph{
    int sz;
    bool dir;
    vector<int> indegree;

    public:
    vector<Edge<CostType>> edges;
    vector<vector<EdgeNum>> connect;

    /**
     * @brief Construct a new Graph object
     * @param VertexNum グラフの頂点数
     * @param isDirected 有向グラフとして作成するか
     */
    Graph(int VertexNum, bool isDirected = false) : sz(VertexNum), dir(isDirected), connect(VertexNum), indegree(VertexNum){}

    Graph() = default;

    /**
     * @brief グラフに頂点sと頂点t間の辺を追加する。
     * @note 有向グラフならば頂点sから頂点tへの有向辺を、無向グラフならば頂点sと頂点tを結ぶ無向辺を追加する。
     * @param s 頂点s
     * @param t 頂点t
     * @param w 辺の重み (option, default = 1)
     */
    void add(Vertex s, Vertex t, CostType w = 1){
        assert(0 <= s && s < sz);
        assert(0 <= t && t < sz);
        EdgeNum e = edges.size();
        edges.push_back(Edge<CostType>(s, t, w));
        connect[s].push_back(e);
        ++indegree[t];
        if(!dir){
            edges.push_back(Edge<CostType>(t, s, w));
            connect[t].push_back(e + 1);
        }
    }

    /**
     * @brief 指定した辺番号の辺を取得する。
     * @param idx 辺番号
     * @return Edge<CostType> 辺情報
     */
    Edge<CostType> get_edge(EdgeNum idx){
        int e = edges.size();
        assert(0 <= idx && idx < e);
        return edges[idx];
    }

    /**
     * @brief 指定した頂点番号に接続する辺の一覧を取得する。
     * @param v 頂点番号
     * @return vector<Edge<CostType>> 指定した頂点番号に接続する辺の一覧
     */
    vector<Edge<CostType>> get_edges(Vertex v){
        assert(0 <= v && v < sz);
        vector<Edge<CostType>> ret;
        for(auto &idx : connect[v]) ret.push_back(get_edge(idx));
        return ret;
    }

    /**
     * @brief 指定した頂点番号に接続する辺番号の一覧を取得する。
     * @param v 頂点番号
     * @return vector<EdgeNum> 指定した頂点番号に接続する辺番号の一覧
     */
    vector<EdgeNum> get_list(Vertex v){
        assert(0 <= v && v < sz);
        return connect[v];
    }

    /**
     * @brief 逆辺を張ったグラフを作成する。
     * @attention この操作は有向グラフにのみ可能である。
     * @return Graph<CostType> 逆辺を張ったグラフ
     */
    Graph<CostType> reverse(){
        assert(dir);
        Graph<CostType> ret(sz, true);
        for(auto &e : edges){
            ret.add(e.to, e.from, e.cost);
        }
        return ret;
    }

    inline size_t size(){
        return sz;
    }

    inline bool directed(){
        return dir;
    }

    /**
     * @brief ある頂点の次数(出次数)を取得する。
     * @note 有向グラフにおいて、第2引数をtrueにすれば入次数を得ることができる。
     * @param v 頂点番号
     * @param isIn (有向グラフのときのみ有効)入次数を取得するか (option, default = false)
     * @return int 頂点vの指定した値
     */
    inline int degree(Vertex v, bool isIn = false){
        if(dir && isIn) return indegree[v];
        return (int)connect[v].size();
    }
};