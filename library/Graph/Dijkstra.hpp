/**
 * @file Dijkstra.hpp
 * @brief Dijkstra - ダイクストラ法
 * @version 3.0
 * @date 2024-01-09
 */

#include "GraphTemplate.hpp"

template<typename CostType>
struct Dijkstra{
    private:
    GraphV<CostType> &G;
    vector<CostType> m_dist, m_potential;
    vector<Vertex> m_prev_vertex;

    public:
    Dijkstra(GraphV<CostType> &G) : G(G){
        m_dist.resize(G.size());
        m_potential.resize(G.size(), 0);
        m_prev_vertex.resize(G.size(), -1);
    }

    vector<CostType> &solve(Vertex s){
        assert(0 <= s and s < G.size());
        m_dist.assign(G.size(), G.INF);
        using p = pair<CostType, Vertex>;
        priority_queue<p, vector<p>, greater<p>> que;
        que.emplace(m_potential[s], s);
        m_dist[s] = m_potential[s];
        while(que.size()){
            auto [d, v] = que.top(); que.pop();
            if(m_dist[v] < d) continue;
            for(auto &e : G[v]){
                if(d + e.cost + m_potential[e.from] - m_potential[e.to] < m_dist[e.to]){
                    m_dist[e.to] = d + e.cost + m_potential[e.from] - m_potential[e.to];
                    m_prev_vertex[e.to] = v;
                    que.emplace(m_dist[e.to], e.to);
                }
            }
        }
        for(Vertex i = 0; i < G.size(); ++i){
            if(m_dist[i] != G.INF){
                m_dist[i] += m_potential[i] - m_potential[s];
            }
        }
        return m_dist;
    }

    vector<CostType> &get(){
        return m_dist;
    }

    vector<CostType> shortest_path(Vertex t){
        vector<CostType> ret{t};
        Vertex now = t;
        while(m_prev_vertex[now] != -1){
            ret.push_back(m_prev_vertex[now]);
            now = m_prev_vertex[now];
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }

    CostType operator[](Vertex v){
        return m_dist.at(v);
    }
};