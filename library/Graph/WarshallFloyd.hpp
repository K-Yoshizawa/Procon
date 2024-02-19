/**
 * @file WarshallFloyd.hpp
 * @author log_K (lX57)
 * @brief WarshallFloyd - 全点対間最短経路
 * @version 2.2
 * @date 2023-10-02
 */

#include "GraphTemplate.hpp"

template<typename CostType>
struct WarshallFloyd{
    private:
    bool m_nc;
    int m_size;
    CostType m_INF;
    vector<vector<CostType>> m_dist;

    void m_solve(){
        for(int k = 0; k < m_size; ++k){
            for(int i = 0; i < m_size; ++i){
                for(int j = 0; j < m_size; ++j){
                    if(m_dist[i][k] == m_INF || m_dist[k][j] == m_INF) continue;
                    m_dist[i][j] = min(m_dist[i][j], m_dist[i][k] + m_dist[k][j]);
                }
            }
        }
        m_nc = false;
        for(int i = 0; i < m_size; ++i) m_nc |= m_dist[i][i] < 0;
    }

    public:
    WarshallFloyd(Graph<CostType> &G) : m_size(G.size()), m_INF(G.INF), m_dist(G.matrix()){
        m_solve();
    }

    WarshallFloyd(vector<vector<CostType>> &M) : m_size((int)M.size()), m_INF(numeric_limits<CostType>::max() / 2), m_dist(M){
        m_solve();
    }

    inline bool negative(){
        return m_nc;
    }

    CostType dist(Vertex Start, Vertex Goal){
        assert(0 <= Start && Start < m_size);
        assert(0 <= Goal && Goal < m_size);
        return m_dist[Start][Goal];
    }
    
    void print(CostType NotAdjacent = numeric_limits<CostType>::max() >> 2, bool DisplayINF = true){
        for(int i = 0; i < m_size; ++i){
            cout << (DisplayINF && m_dist[i][0] == NotAdjacent ? "INF" : to_string(m_dist[i][0]));
            for(int j = 1; j < m_size; ++j){
                cout << " " << (DisplayINF && m_dist[i][j] == NotAdjacent ? "INF" : to_string(m_dist[i][j]));
            }
            cout << endl;
        }
    }
};