#pragma once

#include "Graph.hpp"

template<typename Ordered>
class Dijkstra{
    public:
    Dijkstra(Graph<Ordered> &G, Vertex s = -1) : G(G), V(G.VertexSize()), dist_(V), prev_edge_(V){
        if(s != -1) Solve(s);
    }

    inline bool Reachable(const Vertex &t) const {
        return dist_[t] != inf;
    }

    inline Ordered Distance(const Vertex &t) const {
        return dist_[t];
    }

    vector<Edge<Ordered>> Path(const Vertex &t) const {
        if(!Reachable(t)) return vector<Edge<Ordered>>{};
        vector<Edge<Ordered>> ret;
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
        using P = pair<Ordered, Vertex>;
        fill(dist_.begin(), dist_.end(), inf);
        dist_[s] = Ordered(0);
        fill(prev_edge_.begin(), prev_edge_.end(), Edge<Ordered>{});
        prev_edge_[s] = Edge<Ordered>(-1, -1);
        priority_queue<P, vector<P>, greater<P>> que;
        que.emplace(Ordered(0), s);
        while(que.size()){
            auto [d, u] = que.top(); que.pop();
            if(dist_[u] != d) continue;
            for(const Edge<Ordered> &e : G[u]){
                if(dist_[e.to] > d + e.cost){
                    dist_[e.to] = d + e.cost;
                    prev_edge_[e.to] = e;
                    que.emplace(dist_[e.to], e.to);
                }
            }
        }
    }

    inline Ordered operator[](const Vertex &v){
        return dist_[v];
    }

    inline const Ordered operator[](const Vertex &v) const {
        return dist_[v];
    }

    private:
    Graph<Ordered> &G;
    int V;
    Vertex source_;
    Ordered inf{Ordered(INF)};
    vector<Ordered> dist_;
    vector<Edge<Ordered>> prev_edge_;
};