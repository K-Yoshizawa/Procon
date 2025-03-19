#pragma once

#include "Graph.hpp"

template<typename CostType>
class Dijkstra{
    public:
    Dijkstra(Graph<CostType> &graph, Vertex s = -1) :
        G(graph), n(graph.VertexSize()), dist_(n), prev_edge_(n){
        if(s != -1) Solve_(s);
    }

    inline bool Reachable(const Vertex &t) const {
        return dist_[t] != inf;
    }

    inline CostType Distance(const Vertex &t) const {
        return dist_[t];
    }

    vector<Edge<CostType>> Path(const Vertex &t) const {
        if(!Reachable(t)) return vector<Edge<CostType>>{};
        vector<Edge<CostType>> ret;
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
        using P = pair<CostType, Vertex>;
        fill(dist_.begin(), dist_.end(), inf);
        dist_[s] = CostType(0);
        fill(prev_edge_.begin(), prev_edge_.end(), Edge<CostType>{});
        prev_edge_[s] = Edge<CostType>(-1, -1);
        priority_queue<P, vector<P>, greater<P>> que;
        que.emplace(CostType(0), s);
        while(que.size()){
            auto [d, u] = que.top(); que.pop();
            if(dist_[u] != d) continue;
            for(const Edge<CostType> &e : G[u]){
                if(dist_[e.to] > d + e.cost){
                    dist_[e.to] = d + e.cost;
                    prev_edge_[e.to] = e;
                    que.emplace(dist_[e.to], e.to);
                }
            }
        }
    }

    inline CostType operator[](const Vertex &t){
        return dist_[t];
    }

    inline const CostType operator[](const Vertex &t) const {
        return dist_[t];
    }

    private:
    Graph<CostType> &G;
    int n;
    Vertex source_;
    CostType inf{CostType(INF)};
    vector<CostType> dist_;
    vector<Edge<CostType>> prev_edge_;
};