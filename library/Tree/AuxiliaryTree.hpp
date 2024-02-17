/**
 * @file AuxiliaryTree.hpp
 * @brief Auxiliary Tree - 補助木
 * @version 1.0
 * @date 2024-02-11
 */

#include "EulerTour.hpp"
#include "LowestCommonAncestor.hpp"

template<typename CostType>
struct AuxiliaryTree{
    private:
    Graph<CostType> &G;
    vector<int> m_aux, m_ori, m_par;
    EulerTour<CostType> m_et;
    LowestCommonAncestor<CostType> m_lca;

    public:
    AuxiliaryTree(Graph<CostType> &G, Vertex Root = 0) : G(G), m_et(G, Root), m_lca(G, Root){
        int n = G.size();
        m_aux.resize(n, -1);
        m_ori.resize(n, -1);
        m_par.resize(n, -1);
    }

    /**
     * @brief 頂点集合 `vs` を含む補助木 `T'` を生成する。
     * @param vs 頂点集合
     * @return Graph<CostType> 生成した補助木 `T'`
     */
    Graph<CostType> build(vector<Vertex> &vs){
        int m = vs.size();
        sort(vs.begin(), vs.end(), [&](int i, int j){
            return m_et.in(i) < m_et.in(j);
        });
        for(int i = 0; i < m - 1; ++i){
            vs.push_back(m_lca.get(vs[i], vs[i + 1]));
        }
        sort(vs.begin(), vs.end(), [&](int i, int j){
            return m_et.in(i) < m_et.in(j);
        });
        vs.erase(unique(vs.begin(), vs.end()), vs.end());
        m = vs.size();
        for(int i = 0; i < m; ++i) m_aux[vs[i]] = i, m_ori[i] = vs[i];
        stack<Vertex> st;
        st.push(vs[0]);
        for(int i = 1; i < m; ++i){
            while(m_et.out(st.top()) < m_et.in(vs[i])) st.pop();
            if(st.size()) m_par[vs[i]] = st.top();
            st.push(vs[i]);
        }
        Graph ret(m);
        for(int i = 1; i < m; ++i){
            ret.add(m_aux[m_par[vs[i]]], m_aux[vs[i]]);
        }
        return ret;
    }

    /**
     * @brief 補助木 `T'` における頂点 `v` が元の木 `T` のどの頂点に対応するかを返す関数
     * @param v 最後に生成した補助木 `T'` における頂点 (0-index)
     * @return int 元の木 `T` における頂点番号 (0-index)
     */
    int recall(int v){
        return m_ori[v];
    }

    int operator[](int v){
        return recall(v);
    }
};