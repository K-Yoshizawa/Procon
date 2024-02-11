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
    bool m_is_directed{false};
    vector<vector<Edge<CostType>>> m_adj;
    vector<int> m_indegree;

    public:
    CostType INF{numeric_limits<CostType>::max() >> 2};

    Graph() = default;
    Graph(int vertex_size, bool directed = false) : m_vertex_size(vertex_size), m_is_directed(directed){
        m_adj.resize(vertex_size);
        m_indegree.resize(vertex_size, 0);
    }

    void add(Vertex from, Vertex to, CostType cost = 1){
        assert(0 <= from and from < m_vertex_size);
        assert(0 <= to and to < m_vertex_size);
        Edge<CostType> e1(from, to, cost);
        e1.loc = m_adj[from].size();
        e1.id = m_edge_size;
        m_adj[from].push_back(e1);
        if(m_is_directed){
            ++m_indegree[to];
            return;
        }
        Edge<CostType> e2(to, from, cost);
        e2.loc = m_adj[to].size();
        e2.id = m_edge_size;
        m_adj[to].push_back(e2);
        ++m_edge_size;
    }

    void input(int edge_size, bool weighted = false, bool zero_index = false){
        for(int i = 0; i < edge_size; ++i){
            Vertex s, t; cin >> s >> t;
            if(!zero_index) --s, --t;
            CostType c = 1;
            if(weighted) cin >> c;
            add(s, t, c);
        }
    }

    size_t size(){
        return m_vertex_size;
    }

    int outdegree(Vertex v){
        return (int)m_adj.at(v).size();
    }

    int indegree(Vertex v){
        if(m_is_directed) return m_indegree.at(v);
        else return (int)m_adj.at(v).size();
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

    vector<Edge<CostType>> &get_adj(Vertex v){
        return m_adj.at(v);
    }

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

    void print(){
        for(int i = 0; i < m_vertex_size; ++i){
            cout << "Vertex " << i << " : ";
            for(auto &e : m_adj[i]){
                cout << "{" << e.to << ", " << e.cost << "} ";
            }
            cout << endl;
        }
    }

    vector<Edge<CostType>> &operator[](Vertex v){
        return get_adj(v);
    }
};