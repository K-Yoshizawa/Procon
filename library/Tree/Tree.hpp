#pragma once

/**
 * @file Tree.hpp
 * @brief Tree - 木テンプレート
 * @version 0.1
 * @date 2024-07-29
 */

#include <bits/stdc++.h>
using namespace std;

#include "../Graph/Graph.hpp"

template<typename CostType = int32_t>
class Tree : public Graph<CostType>{
    public:
    using Graph<CostType>::Graph;

    void input(bool weighted_graph = true, bool one_index = true){
        for(int i = 0; i < this->get_vertex_size() - 1; ++i){
            int s, t; cin >> s >> t;
            if(one_index) --s, --t;
            CostType w = 1;
            if(weighted_graph) cin >> w;
            this->add_edge(s, t, w);
        }
    }

    void input(const vector<Vertex> &A, const vector<Vertex> &B, const vector<CostType> &C, bool one_index = true){
        assert(A.size() == this->get_vertex_size() - 1);
        assert(B.size() == this->get_vertex_size() - 1);
        assert(C.size() == this->get_vertex_size() - 1);
        for(int i = 0; i < this->get_vertex_size() - 1; ++i){
            int s = A[i], t = B[i];
            if(one_index) --s, --t;
            this->add_edge(s, t, C[i]);
        }
    }
};

template<typename CostType>
struct TreeEdge{
    Vertex vertex;
    CostType cost;
    TreeEdge(Vertex v = -1, CostType c = 1) : vertex(v), cost(c){}
};

template<typename CostType = int32_t>
class RootedTree{
    private:
    size_t vertex_size_;
    Vertex root_vertex_{0};
    vector<TreeEdge<CostType>> parent_;
    vector<vector<TreeEdge<CostType>>> children_;

    public:
    /**
     * @brief 頂点数 `vertex` で頂点 `root = 0` を根とする根付き木を構築する。
     * @attention `input()` で入力を受け取る形式のときのみ使用可能
     * @param vertex 頂点数
     * @param root 根の頂点 `(default = 0)`
     */
    RootedTree(int vertex, int root = 0) : 
        vertex_size_(vertex), root_vertex_(root),
        parent_(vertex_size_), children_(vertex_size_){}

    /**
     * @brief グラフ `G` から頂点 `root = 0` を根とする根付き木を構築する。
     * @attention `G` は木でなくてはならない
     * @param G 構築元のグラフ
     * @param root 根の頂点 `(default = 0)`
     */
    RootedTree(Graph<CostType> &G, Vertex root = 0) :
        vertex_size_(G.get_vertex_size()), root_vertex_(root),
        parent_(vertex_size_), children_(vertex_size_){
        auto dfs = [&](auto self, Vertex v, Vertex p) -> void {
            for(Edge<CostType> &e : G[v]){
                if(e.to == p) continue;
                parent_[e.to] = TreeEdge<CostType>(v, e.cost);
                children_[v].push_back(TreeEdge<CostType>(e.to, e.cost));
                self(self, e.to, v);
            }
        };
        dfs(dfs, root_vertex_, -1);
    }

    size_t get_vertex_size() const {
        return vertex_size_;
    }

    Vertex get_root() const {
        return root_vertex_;
    }

    TreeEdge<CostType> get_parent(Vertex v) const {
        return parent_[v];
    }

    void input(bool weighted_edge = false, bool one_index = true){
        for(Vertex v = 1; v < vertex_size_; ++v){
            Vertex p; cin >> p;
            if(one_index) --p;
            CostType c = 1;
            if(weighted_edge) cin >> c;
            parent_[v] = TreeEdge<CostType>(p, c);
            children_[p].push_back(TreeEdge<CostType>(v, c));
        }
    }

    vector<TreeEdge<CostType>> &operator[](Vertex v){
        return children_[v];
    }

    const vector<TreeEdge<CostType>> &operator[](Vertex v) const {
        return children_[v];
    }
};

template<typename CostType>
vector<int> calculate_subtree_size(RootedTree<CostType> &T){
    vector<int> ret(T.get_vertex_size(), 1);
    auto dfs = [&](auto self, Vertex v) -> void {
        for(TreeEdge<CostType> &e : T[v]){
            self(self, e.vertex);
            ret[v] += ret[e.vertex];
        }
        return;
    };
    dfs(dfs, T.get_root());
    return ret;
}

template<typename CostType>
vector<int> calculate_depth(RootedTree<CostType> &T){
    vector<int> ret(T.get_vertex_size(), 0);
    auto dfs = [&](auto self, Vertex v) -> void {
        for(TreeEdge<CostType> &e : T[v]){
            ret[e.vertex] = ret[v] + 1;
            self(self, e.vertex);
        }
        return;
    };
    dfs(dfs, T.get_root());
    return ret;
}