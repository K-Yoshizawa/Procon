/**
 * @file LowestCommonAncestor.hpp
 * @brief Lowest Common Ancestor - 最小共通祖先
 * @version 4.0
 * @date 2024-09-03
 */

#include "Tree.hpp"

template<typename CostType>
struct LowestCommonAncestor{
    public:
    LowestCommonAncestor(RootedTree<CostType> &tree) :
            tree_(tree), depth_(CalculateTreeDepth(tree)){
        int V = tree.get_vertex_size();
        height_ = 1;
        while((1 << height_) < V) ++height_;
        parent_.resize(height_, vector<Vertex>(V, -1));
        for(Vertex v = 0; v < V; ++v){
            parent_[0][v] = tree.get_parent(v);
        }
        for(int k = 0; k + 1 < height_; ++k){
            for(Vertex v = 0; v < V; ++v){
                if(parent_[k][v] < 0) parent_[k + 1][v] = -1;
                else parent_[k + 1][v] = parent_[k][parent_[k][v]];
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
    RootedTree<CostType> &tree_;
    int height_;
    vector<int> depth_;
    vector<vector<Vertex>> parent_;
};