/**
 * @file TreeDiameter.hpp
 * @brief Tree Diameter - 木の直径
 * @version 2.0
 * @date 2024-07-29
 */

#include "Tree.hpp"

template<typename CostType>
class TreeDiameter{
    private:
    Tree<CostType> &T;
    vector<Vertex> diameter_path_;
    CostType diameter_cost_;
    vector<CostType> branch_cost_;
    
    void build(){
        // 直径構築パート
        vector<CostType> dist(T.get_vertex_size(), 0);
        vector<Vertex> parent(T.get_vertex_size(), -1);
        auto dfs1 = [&](auto self, Vertex current_vertex, Vertex prev_vertex) -> void {
            for(Edge<CostType> &e : T[current_vertex]){
                if(e.to == prev_vertex) continue;
                dist[e.to] = dist[current_vertex] + e.cost;
                parent[e.to] = current_vertex;
                self(self, e.to, current_vertex);
            }
        };
        Vertex start = 0;
        dfs1(dfs1, start, -1);
        start = distance(dist.begin(), max_element(dist.begin(), dist.end()));
        dist.assign(T.get_vertex_size(), 0);
        parent.assign(T.get_vertex_size(), -1);
        dfs1(dfs1, start, -1);
        auto itr = max_element(dist.begin(), dist.end());
        diameter_cost_ = *itr;
        vector<bool> included_diameter(T.get_vertex_size(), false);
        Vertex current = distance(dist.begin(), itr);
        diameter_path_.push_back(current);
        included_diameter[current] = true;
        while(parent[current] != -1){
            current = parent[current];
            diameter_path_.push_back(current);
            included_diameter[current] = true;
        }

        // 枝構築パート
        branch_cost_.resize(T.get_vertex_size(), 0);
        auto dfs2 = [&](auto self, Vertex current_vertex, Vertex prev_vertex) -> void {
            for(Edge<CostType> &e : T[current_vertex]){
                if(e.to == prev_vertex) continue;
                if(included_diameter[e.to]) continue;
                branch_cost_[e.to] = branch_cost_[current_vertex] + e.cost;
                self(self, e.to, current_vertex);
            }
        };
        for(auto &v : diameter_path_){
            dfs2(dfs2, v, -1);
        }
    }

    public:
    TreeDiameter(Tree<CostType> &T) : T(T){
        build();
    }

    vector<Vertex> &get_path(){
        return diameter_path_;
    }

    pair<Vertex, Vertex> get_endpoints() const {
        return {diameter_path_.front(), diameter_path_.back()};
    }

    CostType get_cost() const {
        return diameter_cost_;
    }

    vector<CostType> &get_branch_cost(){
        return branch_cost_;
    }
};