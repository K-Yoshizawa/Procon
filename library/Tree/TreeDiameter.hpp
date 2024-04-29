/**
 * @file TreeDiameter.hpp
 * @brief Tree Diameter - 木の直径
 * @version 1.0
 * @date 2024-03-01
 */

#include "../Graph/GraphTemplate.hpp"

template<typename CostType>
struct TreeDiameter{
    private:
    Graph<CostType> &G;
    vector<CostType> dist_;
    vector<Vertex> path_;

    void dfs_(int v, int p){
        for(auto &e : G[v]){
            if(p == e.to) continue;
            dist_[e.to] = dist_[v] + e.cost;
            dfs_(e.to, v);
        }
    }

    void recall_(int v){
        path_.push_back(v);
        for(auto &e : G[v]){
            if(dist_[e.to] == dist_[v] - e.cost){
                recall_(e.to);
            }
        }
    }

    public:
    TreeDiameter(Graph<CostType> &G) : G(G){
        dist_.resize(G.size(), 0);
        dfs_(0, -1);
        int v = 0;
        for(int i = 1; i < G.size(); ++i){
            if(dist_[v] < dist_[i]) v = i;
        }
        dist_.assign(G.size(), 0);
        dfs_(v, -1);
        v = 0;
        for(int i = 1; i < G.size(); ++i){
            if(dist_[v] < dist_[i]) v = i;
        }
        recall_(v);
        reverse(path_.begin(), path_.end());
    }

    /**
     * @brief 直径の両端点の頂点番号を返す。
     * @return pair<Vertex, Vertex> 直径の両端点の頂点番号
     */
    pair<Vertex, Vertex> get(){
        return {path_[0], path_.back()};
    }

    /**
     * @brief 直径の長さを返す。
     */
    CostType dist(){
        return dist_[path_.back()];
    }

    /**
     * @brief 直径の頂点列を返す。
     */
    vector<Vertex> &path(){
        return path_;
    }
};