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
    int m_height;
    vector<int> m_depth;
    vector<vector<Vertex>> m_parent;
    vector<CostType> m_cum;

    void m_dfs(Vertex v, Vertex p, int d){
        m_parent[0][v] = p;
        m_depth[v] = d;
        for(auto &e : G[v]){
            if(e.to != p){
                m_cum[e.to] = m_cum[v] + e.cost;
                m_dfs(e.to, v, d + 1);
            }
        }
    }

    public:
    /**
     * @brief Construct a new Lowest Common Ancestor object
     * @param G 木
     * @param Root 根の頂点番号(0-index)
     */
    LowestCommonAncestor(Graph<CostType> &G, Vertex Root = 0) : G(G), m_height(32){
        m_depth.resize(G.size());
        m_parent.resize(m_height, vector<Vertex>(G.size(), -1));
        m_cum.resize(G.size(), 0);
        m_dfs(Root, -1, 0);
        for(int k = 0; k + 1 < m_height; ++k){
            for(Vertex v = 0; v < G.size(); ++v){
                if(m_parent[k][v] < 0) m_parent[k + 1][v] = -1;
                else m_parent[k + 1][v] = m_parent[k][m_parent[k][v]];
            }
        }
    }

    /**
     * @brief 頂点 `u` と頂点 `v` の LCA を求める。
     * @note 頂点番号は 0-index
     * @return Vertex LCAの頂点番号
     */
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

    /**
     * @brief 頂点 `u` と頂点 `v` 間のコストを求める。
     * @note 頂点番号は 0-index
     * @return CostType コスト
     */
    CostType dist(Vertex u, Vertex v){
        return m_cum[u] + m_cum[v] - m_cum[get(u, v)] * 2;
    }
};