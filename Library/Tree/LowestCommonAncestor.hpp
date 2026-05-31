#pragma once

#include "Tree.hpp"
#include "../DataStructure/SparseTable.hpp"

template<typename WeightType>
struct LowestCommonAncestor{
    public:
    LowestCommonAncestor(Graph<WeightType> &T, Vertex r = 0) : T(T){
        index_.resize(T.VertexSize());
        auto depth = CalculateTreeDepth(T, r);
        vector<pair<int, int>> A;
        auto dfs = [&](auto self, int v, int p) -> void {
            index_[v] = A.size();
            A.push_back({depth[v], v});
            for(const auto &e : T[v]){
                if(e.to == p) continue;
                self(self, e.to, v);
                A.push_back({depth[v], v});
            }
        };
        dfs(dfs, r, -1);
        st = SparseTable<pair<int, int>>(
            A,
            [](pair<int, int> l, pair<int, int> r){
                if(l.first < r.first) return l;
                else return r;
            }
        );
    }

    Vertex Query(Vertex u, Vertex v) const {
        if(index_[u] > index_[v]) swap(u, v);
        return st.Query(index_[u], index_[v] + 1).second;
    }

    private:
    Graph<WeightType> &T;
    SparseTable<pair<int, int>> st;
    vector<int> index_;
};