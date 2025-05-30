#pragma once

#include "Tree.hpp"

template<typename CostType>
struct LowestCommonAncestor{
    public:
    LowestCommonAncestor(Graph<CostType> &tree) : T(tree), depth_(CalculateTreeDepth(tree)){
        int n = T.VertexSize();
        height_ = 1;
        while((1 << height_) < n) ++height_;
        auto par = CalculateTreeParent(T);
        parent_.resize(height_, vector<Vertex>(n, -1));
        for(Vertex i = 0; i < n; ++i){
            parent_[0][i] = par[i];
        }
        for(int k = 0; k + 1 < height_; ++k){
            for(Vertex i = 0; i < n; ++i){
                if(parent_[k][i] < 0) parent_[k + 1][i] = -1;
                else parent_[k + 1][i] = parent_[k][parent_[k][i]];
            }
        }
    }

    /**
     * @brief 頂点 `u` と頂点 `v` の最小共通祖先を返す。
     * @param u 頂点番号 (0-index)
     * @param v 頂点番号 (0-index)
     * @return Vertex 頂点 `u` と頂点 `v` の最小共通祖先
     */
    Vertex Query(Vertex u, Vertex v){
        if(depth_[u] < depth_[v]) swap(u, v);
        for(int k = 0; k < height_; ++k){
            if((depth_[u] - depth_[v]) >> k & 1){
                u = parent_[k][u];
            }
        }
        if(u == v) return u;
        for(int k = height_ - 1; k >= 0; --k){
            if(parent_[k][u] != parent_[k][v]){
                u = parent_[k][u];
                v = parent_[k][v];
            }
        }
        return parent_[0][u];
    }

    private:
    Graph<CostType> &T;
    int height_;
    vector<int> depth_;
    vector<vector<Vertex>> parent_;
};