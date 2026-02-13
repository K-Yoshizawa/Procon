#pragma once

#include "Graph.hpp"

template<typename WeightType>
class Dijkstra{
    public:
    Dijkstra(Graph<WeightType> &graph, Vertex s = -1) :
        G(graph), V(graph.VertexSize()), dist_(V), prev_edge_(V){
        if(s != -1) Solve(s);
    }

    inline bool Reachable(const Vertex &t) const {
        return dist_[t] != inf;
    }

    inline WeightType Distance(const Vertex &t) const {
        return dist_[t];
    }

    vector<Edge<WeightType>> Path(const Vertex &t) const {
        if(!Reachable(t)) return vector<Edge<WeightType>>{};
        vector<Edge<WeightType>> ret;
        int v = t;
        while(1){
            if(prev_edge_[v].from == -1) break;
            ret.push_back(prev_edge_[v]);
            v = prev_edge_[v].from;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }

    void Solve(Vertex s){
        using P = pair<WeightType, Vertex>;
        fill(dist_.begin(), dist_.end(), inf);
        dist_[s] = WeightType(0);
        fill(prev_edge_.begin(), prev_edge_.end(), Edge<WeightType>{});
        prev_edge_[s] = Edge<WeightType>(-1, -1);
        priority_queue<P, vector<P>, greater<P>> que;
        que.emplace(WeightType(0), s);
        while(que.size()){
            auto [d, u] = que.top(); que.pop();
            if(dist_[u] != d) continue;
            for(const Edge<WeightType> &e : G[u]){
                if(dist_[e.to] > d + e.cost){
                    dist_[e.to] = d + e.cost;
                    prev_edge_[e.to] = e;
                    que.emplace(dist_[e.to], e.to);
                }
            }
        }
    }

    inline WeightType operator[](const Vertex &v){
        return dist_[v];
    }

    inline const WeightType operator[](const Vertex &v) const {
        return dist_[v];
    }

    private:
    Graph<WeightType> &G;
    int V;
    Vertex source_;
    WeightType inf{WeightType(INF)};
    vector<WeightType> dist_;
    vector<Edge<WeightType>> prev_edge_;
};