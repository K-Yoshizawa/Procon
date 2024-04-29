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
    int vertex_size_{0}, edge_size_{0};
    bool is_directed_{false}, is_weighted_{false};
    vector<vector<Edge<CostType>>> adj_;
    vector<int> indegree_;

    public:
    CostType INF{numeric_limits<CostType>::max() >> 2};

    Graph() = default;

    /**
     * @brief `vertex_size` 頂点 `0` 辺のグラフを作成する。
     * @note `directed` を `true` にすると有向グラフになる。
     * @param vertex_size 頂点数
     * @param directed 有向グラフを作成するか (option, default = `false`)
     */
    Graph(int vertex_size, bool directed = false) : vertex_size_(vertex_size), is_directed_(directed){
        adj_.resize(vertex_size);
        indegree_.resize(vertex_size, 0);
    }

    /**
     * @brief 頂点 `from` から頂点 `to` に辺を張る。
     * @note `cost` を指定することで重みをつけることができる。
     * @param from 頂点番号
     * @param to 頂点番号
     * @param cost 重み (option, default = `1`)
     */
    void add(Vertex from, Vertex to, CostType cost = 1){
        assert(0 <= from and from < vertex_size_);
        assert(0 <= to and to < vertex_size_);
        is_weighted_ |= cost > 1;
        Edge<CostType> e1(from, to, cost);
        e1.loc = adj_[from].size();
        e1.id = edge_size_;
        adj_[from].push_back(e1);
        ++edge_size_;
        if(is_directed_){
            ++indegree_[to];
            return;
        }
        Edge<CostType> e2(to, from, cost);
        e2.loc = adj_[to].size();
        e2.id = e1.id;
        adj_[to].push_back(e2);
    }

    /**
     * @brief グラフに `edge_size` 本の辺を入力させる。
     * @param edge_size 入力する辺数
     * @param weighted 重み付き辺か (option, default = `false`)
     * @param zero_index 入力の頂点番号が 0-index か (option, default = `false`)
     */
    void input(int edge_size, bool weighted = false, bool zero_index = false){
        is_weighted_ = weighted;
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
        return vertex_size_;
    }

    /**
     * @brief 頂点 `v` の出次数を返す。
     * @param v 頂点番号
     * @return int 頂点 `v` の出次数
     */
    int outdegree(Vertex v){
        return (int)adj_.at(v).size();
    }

    /**
     * @brief 頂点 `v` の入次数を返す。
     * @param v 頂点番号
     * @return int 頂点 `v` の入次数
     */
    int indegree(Vertex v){
        if(is_directed_) return indegree_.at(v);
        else return (int)adj_.at(v).size();
    }

    /**
     * @brief グラフが有向グラフかどうかを返す。
     */
    bool is_directed(){
        return is_directed_;
    }

    /**
     * @brief グラフが重み付きかどうかを返す。
     */
    bool is_weighted(){
        return is_weighted_;
    }

    vector<Vertex> source(){
        assert(is_directed_);
        vector<Vertex> ret;
        for(int i = 0; i < vertex_size_; ++i){
            if(indegree(i) == 0) ret.push_back(i);
        }
        return ret;
    }

    vector<Vertex> sink(){
        vector<Vertex> ret;
        for(int i = 0; i < vertex_size_; ++i){
            if(outdegree(i) == 0) ret.push_back(i);
        }
        return ret;
    }

    vector<Vertex> leaf(){
        vector<Vertex> ret;
        for(int i = 0; i < vertex_size_; ++i){
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
        return adj_.at(v);
    }

    /**
     * @brief 辺の向きをすべて逆にしたグラフを返す。
     * @attention 有向グラフであることを要件とする。
     * @return Graph<CostType> 逆辺グラフ
     */
    Graph<CostType> reverse(){
        assert(is_directed_);
        Graph ret(vertex_size_, true);
        for(auto es : adj_){
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
        assert(is_directed_);
        vector<Vertex> ret;
        queue<Vertex> que;
        vector<int> cnt(vertex_size_, 0);
        for(auto v : source()) que.push(v);
        while(que.size()){
            Vertex v = que.front(); que.pop();
            ret.push_back(v);
            for(int u : adj_[v]){
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
        vector<int> es(edge_size_, 0);
        for(int i = 0; i < vertex_size_; ++i){
            for(auto e : adj_[i]){
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

    vector<vector<CostType>> matrix(){
        int n = vertex_size_;
        vector<vector<CostType>> ret(n, vector<CostType>(n, INF));
        for(int i = 0; i < n; ++i) ret[i][i] = 0;
        for(int v = 0; v < n; ++v){
            for(auto &e : adj_[v]){
                ret[v][e.to] = e.cost;
            }
        }
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