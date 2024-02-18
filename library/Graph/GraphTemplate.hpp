#pragma once

/**
 * @file GraphTemplate.hpp
 * @brief Graph Template - グラフテンプレート
 * @version 3.0
 * @date 2024-01-09
 */

#include <bits/stdc++.h>
using namespace std;

using Vertex = int;

template<typename CostType>
struct Edge{
    public:
    Vertex from, to;
    CostType cost;
    int loc{-1}, id{-1};

    Edge() = default;
    Edge(Vertex from, Vertex to, CostType cost) : from(from), to(to), cost(cost){}

    operator int(){
        return to;
    }
};

template<typename CostType = int>
struct Graph{
    private:
    int m_vertex_size{0}, m_edge_size{0};
    bool m_is_directed{false}, m_is_weighted{false};
    vector<vector<Edge<CostType>>> m_adj;
    vector<int> m_indegree;

    public:
    CostType INF{numeric_limits<CostType>::max() >> 2};

    Graph() = default;

    /**
     * @brief `vertex_size` 頂点 `0` 辺のグラフを作成する。
     * @note `directed` を `true` にすると有向グラフになる。
     * @param vertex_size 頂点数
     * @param directed 有向グラフを作成するか (option, default = `false`)
     */
    Graph(int vertex_size, bool directed = false) : m_vertex_size(vertex_size), m_is_directed(directed){
        m_adj.resize(vertex_size);
        m_indegree.resize(vertex_size, 0);
    }

    /**
     * @brief 頂点 `from` から頂点 `to` に辺を張る。
     * @note `cost` を指定することで重みをつけることができる。
     * @param from 頂点番号
     * @param to 頂点番号
     * @param cost 重み (option, default = `1`)
     */
    void add(Vertex from, Vertex to, CostType cost = 1){
        assert(0 <= from and from < m_vertex_size);
        assert(0 <= to and to < m_vertex_size);
        m_is_weighted |= cost > 1;
        Edge<CostType> e1(from, to, cost);
        e1.loc = m_adj[from].size();
        e1.id = m_edge_size;
        m_adj[from].push_back(e1);
        ++m_edge_size;
        if(m_is_directed){
            ++m_indegree[to];
            return;
        }
        Edge<CostType> e2(to, from, cost);
        e2.loc = m_adj[to].size();
        e2.id = e1.id;
        m_adj[to].push_back(e2);
    }

    /**
     * @brief グラフに `edge_size` 本の辺を入力させる。
     * @param edge_size 入力する辺数
     * @param weighted 重み付き辺か (option, default = `false`)
     * @param zero_index 入力の頂点番号が 0-index か (option, default = `false`)
     */
    void input(int edge_size, bool weighted = false, bool zero_index = false){
        m_is_weighted = weighted;
        for(int i = 0; i < edge_size; ++i){
            Vertex s, t; cin >> s >> t;
            if(!zero_index) --s, --t;
            CostType c = 1;
            if(weighted) cin >> c;
            add(s, t, c);
        }
    }

    /**
     * @brief グラフの頂点数を返す。
     * @return size_t 頂点数
     */
    size_t size(){
        return m_vertex_size;
    }

    /**
     * @brief 頂点 `v` の出次数を返す。
     * @param v 頂点番号
     * @return int 頂点 `v` の出次数
     */
    int outdegree(Vertex v){
        return (int)m_adj.at(v).size();
    }

    /**
     * @brief 頂点 `v` の入次数を返す。
     * @param v 頂点番号
     * @return int 頂点 `v` の入次数
     */
    int indegree(Vertex v){
        if(m_is_directed) return m_indegree.at(v);
        else return (int)m_adj.at(v).size();
    }

    bool is_weighted(){
        return m_is_weighted;
    }

    vector<Vertex> source(){
        assert(m_is_directed);
        vector<Vertex> ret;
        for(int i = 0; i < m_vertex_size; ++i){
            if(indegree(i) == 0) ret.push_back(i);
        }
        return ret;
    }

    vector<Vertex> sink(){
        vector<Vertex> ret;
        for(int i = 0; i < m_vertex_size; ++i){
            if(outdegree(i) == 0) ret.push_back(i);
        }
        return ret;
    }

    vector<Vertex> leaf(){
        vector<Vertex> ret;
        for(int i = 0; i < m_vertex_size; ++i){
            if(indegree(i) == 1) ret.push_back(i);
        }
        return ret;
    }

    /**
     * @brief 頂点 `v` の隣接リストを返す。
     * @param v 頂点番号
     * @return vector<Edge<CostType>>& 頂点 `v` の隣接リスト
     */
    vector<Edge<CostType>> &get_adj(Vertex v){
        return m_adj.at(v);
    }

    /**
     * @brief 辺の向きをすべて逆にしたグラフを返す。
     * @attention 有向グラフであることを要件とする。
     * @return Graph<CostType> 逆辺グラフ
     */
    Graph<CostType> reverse(){
        assert(m_is_directed);
        Graph ret(m_vertex_size, true);
        for(auto es : m_adj){
            for(auto e : es){
                ret.add(e.to, e.from, e.cost);
            }
        }
        return ret;
    }

    /**
     * @brief トポロジカルソートした頂点列を返す。
     * @attention 有向グラフであることを要件とする。
     * @return vector<Vertex> トポロジカルソートした頂点列
     */
    vector<Vertex> topological_sort(){
        assert(m_is_directed);
        vector<Vertex> ret;
        queue<Vertex> que;
        vector<int> cnt(m_vertex_size, 0);
        for(auto v : source()) que.push(v);
        while(que.size()){
            Vertex v = que.front(); que.pop();
            ret.push_back(v);
            for(int u : m_adj[v]){
                if(++cnt[u] == indegree(u)) que.push(u);
            }
        }
        return ret;
    }

    /**
     * @brief グラフから辺集合を作成する。
     * @note 辺集合は重みで昇順ソートされた状態で返される。
     * @return vector<Edge<CostType>> 辺集合
     */
    vector<Edge<CostType>> edge_set(){
        vector<Edge<CostType>> ret;
        vector<int> es(m_edge_size, 0);
        for(int i = 0; i < m_vertex_size; ++i){
            for(auto e : m_adj[i]){
                if(es[e.id]) continue;
                es[e.id] = 1;
                ret.push_back(e);
            }
        }
        sort(ret.begin(), ret.end(), [&](Edge<CostType> &l, Edge<CostType> &r){
            return l.cost < r.cost;
        });
        return ret;
    }

    friend ostream &operator<<(ostream &os, Graph<CostType> &G){
        for(int i = 0; i < G.size(); ++i){
            os << "Vertex " << i << " : ";
            if(G[i].empty()){
                os << "<none>" << endl;
                continue;
            }
            for(auto &e : G[i]){
                if(G.is_weighted()) os << "{" << e.to << ", " << e.cost << "} ";
                else os << e.to << " ";
            }
            if(i + 1 < G.size()) os << endl;
        }
        return os;
    }

    vector<Edge<CostType>> &operator[](Vertex v){
        return get_adj(v);
    }
};