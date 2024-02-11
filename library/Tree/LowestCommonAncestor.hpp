/**
 * @file LowestCommonAncestor.hpp
 * @author log K (lX57)
 * @brief Lowest Common Ancestor - 最小共通祖先
 * @version 3.0
 * @date 2024-02-11
 */

#include "../Graph/GraphTemplate.hpp"

template<typename CostType>
struct LowestCommonAncestor{
    private:
    Graph<CostType> &G;
    int m_height;
    vector<int> m_depth;
    vector<vector<Vertex>> m_parent;

    void m_dfs(Vertex v, Vertex p, int d){
        m_parent[0][v] = p;
        m_depth[v] = d;
        for(auto &e : G[v]){
            if(e.to != p) m_dfs(e.to, v, d + 1);
        }
    }

    public:
    LowestCommonAncestor(Graph<CostType> &G, Vertex Root = 0) : G(G), m_height(32){
        m_depth.resize(G.size());
        m_parent.resize(m_height, vector<Vertex>(G.size(), -1));
        m_dfs(Root, -1, 0);
        for(int k = 0; k + 1 < m_height; ++k){
            for(Vertex v = 0; v < G.size(); ++v){
                if(m_parent[k][v] < 0) m_parent[k + 1][v] = -1;
                else m_parent[k + 1][v] = m_parent[k][m_parent[k][v]];
            }
        }
    }

    Vertex get(Vertex u, Vertex v){
        if(m_depth[u] > m_depth[v]) swap(u, v);
        for(int k = 0; k < m_height; ++k){
            if((m_depth[v] - m_depth[u]) >> k & 1){
                v = m_parent[k][v];
            }
        }
        if(u == v) return u;
        for(int k = m_height - 1; k >= 0; --k){
            if(m_parent[k][u] != m_parent[k][v]){
                u = m_parent[k][u];
                v = m_parent[k][v];
            }
        }
        return m_parent[0][u];
    }
};