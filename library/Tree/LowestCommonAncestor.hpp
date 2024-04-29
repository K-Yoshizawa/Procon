/**
 * @file LowestCommonAncestor.hpp
 * @brief Lowest Common Ancestor - 最小共通祖先
 * @version 3.0
 * @date 2024-02-11
 */

#include "../Graph/GraphTemplate.hpp"

template<typename CostType>
struct LowestCommonAncestor{
    private:
    Graph<CostType> &G;
    int height_;
    vector<int> depth_;
    vector<vector<Vertex>> parent_;
    vector<CostType> cum_;

    void dfs_(Vertex v, Vertex p, int d){
        parent_[0][v] = p;
        depth_[v] = d;
        for(auto &e : G[v]){
            if(e.to != p){
                cum_[e.to] = cum_[v] + e.cost;
                dfs_(e.to, v, d + 1);
            }
        }
    }

    public:
    /**
     * @brief Construct a new Lowest Common Ancestor object
     * @param G 木
     * @param Root 根の頂点番号(0-index)
     */
    LowestCommonAncestor(Graph<CostType> &G, Vertex Root = 0) : G(G), height_(32){
        depth_.resize(G.size());
        parent_.resize(height_, vector<Vertex>(G.size(), -1));
        cum_.resize(G.size(), 0);
        dfs_(Root, -1, 0);
        for(int k = 0; k + 1 < height_; ++k){
            for(Vertex v = 0; v < G.size(); ++v){
                if(parent_[k][v] < 0) parent_[k + 1][v] = -1;
                else parent_[k + 1][v] = parent_[k][parent_[k][v]];
            }
        }
    }

    /**
     * @brief 頂点 `u` と頂点 `v` の LCA を求める。
     * @note 頂点番号は 0-index
     * @return Vertex LCAの頂点番号
     */
    Vertex get(Vertex u, Vertex v){
        if(depth_[u] > depth_[v]) swap(u, v);
        for(int k = 0; k < height_; ++k){
            if((depth_[v] - depth_[u]) >> k & 1){
                v = parent_[k][v];
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

    /**
     * @brief 頂点 `u` と頂点 `v` 間のコストを求める。
     * @note 頂点番号は 0-index
     * @return CostType コスト
     */
    CostType dist(Vertex u, Vertex v){
        return cum_[u] + cum_[v] - cum_[get(u, v)] * 2;
    }
};