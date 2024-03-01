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
    vector<CostType> m_dist;
    vector<Vertex> m_path;

    void m_dfs(int v, int p){
        for(auto &e : G[v]){
            if(p == e.to) continue;
            m_dist[e.to] = m_dist[v] + e.cost;
            m_dfs(e.to, v);
        }
    }

    void m_recall(int v){
        m_path.push_back(v);
        for(auto &e : G[v]){
            if(m_dist[e.to] == m_dist[v] - e.cost){
                m_recall(e.to);
            }
        }
    }

    public:
    TreeDiameter(Graph<CostType> &G) : G(G){
        m_dist.resize(G.size(), 0);
        m_dfs(0, -1);
        int v = 0;
        for(int i = 1; i < G.size(); ++i){
            if(m_dist[v] < m_dist[i]) v = i;
        }
        m_dist.assign(G.size(), 0);
        m_dfs(v, -1);
        v = 0;
        for(int i = 1; i < G.size(); ++i){
            if(m_dist[v] < m_dist[i]) v = i;
        }
        m_recall(v);
        reverse(m_path.begin(), m_path.end());
    }

    /**
     * @brief 直径の両端点の頂点番号を返す。
     * @return pair<Vertex, Vertex> 直径の両端点の頂点番号
     */
    pair<Vertex, Vertex> get(){
        return {m_path[0], m_path.back()};
    }

    /**
     * @brief 直径の長さを返す。
     */
    CostType dist(){
        return m_dist[m_path.back()];
    }

    /**
     * @brief 直径の頂点列を返す。
     */
    vector<Vertex> &path(){
        return m_path;
    }
};