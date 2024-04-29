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
    vector<int> aux_, ori_, par_;
    EulerTour<CostType> et_;
    LowestCommonAncestor<CostType> lca_;

    public:
    AuxiliaryTree(Graph<CostType> &G, Vertex Root = 0) : G(G), et_(G, Root), lca_(G, Root){
        int n = G.size();
        aux_.resize(n, -1);
        ori_.resize(n, -1);
        par_.resize(n, -1);
    }

    /**
     * @brief 頂点集合 `vs` を含む補助木 `T'` を生成する。
     * @param vs 頂点集合
     * @return Graph<CostType> 生成した補助木 `T'`
     */
    Graph<CostType> build(vector<Vertex> &vs){
        int m = vs.size();
        sort(vs.begin(), vs.end(), [&](int i, int j){
            return et_.in(i) < et_.in(j);
        });
        for(int i = 0; i < m - 1; ++i){
            vs.push_back(lca_.get(vs[i], vs[i + 1]));
        }
        sort(vs.begin(), vs.end(), [&](int i, int j){
            return et_.in(i) < et_.in(j);
        });
        vs.erase(unique(vs.begin(), vs.end()), vs.end());
        m = vs.size();
        for(int i = 0; i < m; ++i) aux_[vs[i]] = i, ori_[i] = vs[i];
        stack<Vertex> st;
        st.push(vs[0]);
        for(int i = 1; i < m; ++i){
            while(et_.out(st.top()) < et_.in(vs[i])) st.pop();
            if(st.size()) par_[vs[i]] = st.top();
            st.push(vs[i]);
        }
        Graph ret(m);
        for(int i = 1; i < m; ++i){
            ret.add(aux_[par_[vs[i]]], aux_[vs[i]]);
        }
        return ret;
    }

    /**
     * @brief 補助木 `T'` における頂点 `v` が元の木 `T` のどの頂点に対応するかを返す関数
     * @param v 最後に生成した補助木 `T'` における頂点 (0-index)
     * @return int 元の木 `T` における頂点番号 (0-index)
     */
    int recall(int v){
        return ori_[v];
    }

    int operator[](int v){
        return recall(v);
    }
};