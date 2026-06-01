#pragma once

#include "Tree.hpp"

template<typename Ordered>
struct LowestCommonAncestor{
    public:
    using P = pair<int, int>;

    LowestCommonAncestor(Graph<Ordered> &T) : T(T){
        int V = (int)T.VertexSize(), r = 0;
        while(1 << (r + 1) <= 2 * V) ++r;
        sparse_table_.resize(r + 1, vector<P>(2 * V));
        leftest_.resize(V);
        auto depth = CalculateTreeDepth(T);
        vector<P> A;
        int index = 0;
        auto dfs = [&](auto self, Vertex v, Vertex p) -> void {
            leftest_[v] = index;
            sparse_table_[0][index++] = {depth[v], v};
            for(const auto &e : T[v]){
                if(e.to == p) continue;
                self(self, e.to, v);
                sparse_table_[0][index++] = {depth[v], v};
            }
        };
        dfs(dfs, 0, -1);
        for(int k = 0; k < r; ++k){
            for(int i = 0; i + (1 << k) < 2 * V; ++i){
                sparse_table_[k + 1][i] = min(sparse_table_[k][i], sparse_table_[k][i + (1 << k)]);
            }
        }
    }

    Vertex Query(Vertex u, Vertex v) const {
        if(leftest_[u] > leftest_[v]) swap(u, v);
        int k = bit_width((uint32_t)leftest_[v] - leftest_[u]) - 1;
        return min(sparse_table_[k][leftest_[u]], sparse_table_[k][leftest_[v] - (1 << k)]).second;
    }

    private:
    Graph<Ordered> &T;
    vector<vector<P>> sparse_table_;
    vector<int> leftest_;
};