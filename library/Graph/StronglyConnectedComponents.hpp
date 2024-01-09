/**
 * @file StronglyConnectedComponents.hpp
 * @brief Strongly Connected Components - 強連結成分分解
 * @version 3.0
 * @date 2024-01-09
 */

#include "GraphTemplate.hpp"

template<typename CostType>
struct StronglyConnectedComponents{
    private:
    GraphV<CostType> &G;
    GraphV<CostType> rG;
    vector<int> m_visited, m_order, m_belong;
    vector<vector<Vertex>> m_member;

    void f_dfs(Vertex v){
        m_visited[v] = 1;
        for(auto &e : G[v]){
            if(!m_visited[e.to]) f_dfs(e.to);
        }
        m_order.push_back(v);
    }

    void f_rdfs(Vertex v, int k){
        m_visited[v] = 0;
        m_belong[v] = k;
        m_member[k].push_back(v);
        for(auto &e : rG[v]){
            if(m_visited[e.to]) f_rdfs(e.to, k);
        }
    }

    public:
    StronglyConnectedComponents(GraphV<CostType> &G) : G(G){
        rG = G.reverse();
        m_visited.resize(G.size(), 0);
        m_belong.resize(G.size(), -1);
        for(int i = 0; i < G.size(); ++i){
            if(!m_visited[i]) f_dfs(i);
        }
        int k = 0;
        for(int i = m_order.size() - 1; i >= 0; --i){
            if(m_visited[m_order[i]]){
                m_member.push_back(vector<CostType>{});
                f_rdfs(m_order[i], k++);
            }
        }
    }

    int where(Vertex v){
        return m_belong.at(v);
    }

    bool same(Vertex u, Vertex v){
        return where(u) == where(v);
    }

    vector<vector<Vertex>> &get(){
        return m_member;
    }

    GraphV<CostType> build(){
        GraphV<CostType> ret(m_member.size(), true);
        for(int i = 0; i < G.size(); ++i){
            int from = where(i);
            for(auto &e : G[i]){
                int to = where(e.to);
                if(from == to) continue;
                ret.add(from, to, e.cost);
            }
        }
        return ret;
    }

    int operator[](Vertex v){
        return where(v);
    }

    void print(){
        for(int i = 0; i < m_member.size(); ++i){
            cout << "Component " << i << " : ";
            for(auto v : m_member[i]){
                cout << v << " ";
            }
            cout << endl;
        }
    }
};