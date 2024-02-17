/**
 * @file EulerTour.hpp
 * @brief Euler Tour - オイラーツアー
 * @version 3.0
 * @date 2024-02-11
 */

#include "../Graph/GraphTemplate.hpp"

template<typename CostType>
struct EulerTour{
    private:
    Graph<CostType> &G;
    vector<int> m_in, m_out;

    void m_dfs(Vertex v, Vertex p, int &t){
        m_in[v] = t++;
        for(auto &e : G[v]){
            if(e.to == p) continue;
            m_dfs(e.to, v, t);
        }
        m_out[v] = t++;
    }

    public:
    /**
     * @brief Construct a new Euler Tour object
     * @param G 木
     * @param Root 根の頂点番号(0-index)
     * @param Offset タイムスタンプの初期値
     */
    EulerTour(Graph<CostType> &G, Vertex Root = 0, int Offset = 0) : G(G){
        m_in.resize(G.size());
        m_out.resize(G.size());
        m_dfs(Root, -1, Offset);
    }

    int in(Vertex v){
        assert(0 <= v && v < G.size());
        return m_in[v];
    }

    int out(Vertex v){
        assert(0 <= v && v < G.size());
        return m_out[v];
    }

    pair<vector<int>, vector<int>> get(){
        return make_pair(m_in, m_out);
    }

    pair<int, int> operator[](Vertex v){
        return make_pair(in(v), out(v));
    }
};