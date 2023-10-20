/**
 * @file EulerTour.hpp
 * @author log K (lX57)
 * @brief Euler Tour - オイラーツアー
 * @version 2.0
 * @date 2023-10-20
 */

#include "../Graph/GraphTemplate.hpp"

template<typename CostType>
struct EulerTour{
    private:
    Graph<CostType> &G;
    Vertex __Root;
    vector<int> __In, __Out;
    int __timer;

    void __dfs(Vertex now, Vertex par){
        __In[now] = __timer++;
        for(auto e : G.get_incident(now)){
            if(e.to == par) continue;
            __dfs(e.to, now);
        }
        __Out[now] = __timer++;
    }

    public:
    /**
     * @brief Euler Tourを構築する。
     * @param G 構築するグラフ
     * @param Root 根とする頂点番号 (default = `0`)
     * @note `timer` は `1` から始まる(セグ木などに1-indexで載せられる)
     */
    EulerTour(Graph<CostType> &G, Vertex Root = 0) : G(G), __Root(Root), __In(G.vsize(), -1), __Out(G.vsize(), -1){
        __timer = 1;
        __dfs(__Root, -1);
    }

    int in(Vertex v){
        assert(0 <= v && v < G.vsize());
        return __In[v];
    }

    int out(Vertex v){
        assert(0 <= v && v < G.vsize());
        return __Out[v];
    }

    /**
     * @brief 頂点 `v` の `in` と `out` を同時に取得する
     * @param v 頂点番号
     * @return pair<int, int> `{in(v), out(v)}`
     */
    pair<int, int> operator[](Vertex v){
        return make_pair(in(v), out(v));
    }
};