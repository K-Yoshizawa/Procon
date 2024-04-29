/**
 * @file Dijkstra.hpp
 * @brief Dijkstra - ダイクストラ法
 * @version 3.1
 * @date 2024-02-11
 */

#include "GraphTemplate.hpp"

template<typename CostType>
struct Dijkstra{
    private:
    Graph<CostType> &G;
    vector<CostType> dist_, potential_;
    vector<Vertex> prev_vertex_;

    public:
    Dijkstra(Graph<CostType> &G) : G(G){
        dist_.resize(G.size());
        potential_.resize(G.size(), 0);
        prev_vertex_.resize(G.size(), -1);
    }

    vector<CostType> &solve(Vertex s){
        assert(0 <= s and s < G.size());
        dist_.assign(G.size(), G.INF);
        using p = pair<CostType, Vertex>;
        priority_queue<p, vector<p>, greater<p>> que;
        que.emplace(potential_[s], s);
        dist_[s] = potential_[s];
        while(que.size()){
            auto [d, v] = que.top(); que.pop();
            if(dist_[v] < d) continue;
            for(auto &e : G[v]){
                if(d + e.cost + potential_[e.from] - potential_[e.to] < dist_[e.to]){
                    dist_[e.to] = d + e.cost + potential_[e.from] - potential_[e.to];
                    prev_vertex_[e.to] = v;
                    que.emplace(dist_[e.to], e.to);
                }
            }
        }
        for(Vertex i = 0; i < G.size(); ++i){
            if(dist_[i] != G.INF){
                dist_[i] += potential_[i] - potential_[s];
            }
        }
        return dist_;
    }

    void update_potential(vector<CostType> &potential){
        assert(potential.size() == G.size());
        potential_ = potential;
    }

    vector<CostType> &get(){
        return dist_;
    }

    vector<CostType> shortest_path(Vertex t){
        vector<CostType> ret{t};
        Vertex now = t;
        while(prev_vertex_[now] != -1){
            ret.push_back(prev_vertex_[now]);
            now = prev_vertex_[now];
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }

    CostType operator[](Vertex v){
        return dist_.at(v);
    }
};