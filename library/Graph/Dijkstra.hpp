/**
 * @file Dijkstra.hpp
 * @brief Dijkstra - ダイクストラ法
 * @version 4.0
 * @date 2024-06-15
 */

#include "Graph.hpp"

template<typename CostType>
class Dijkstra{
    Graph<CostType> &graph_;

    CostType infty_{numeric_limits<CostType>::max() >> 2};
    vector<CostType> distance_;
    vector<Vertex> prev_vertex_;
    Vertex start_vertex_{-1};

    public:
    Dijkstra(Graph<CostType> &G) : 
        graph_(G), distance_(G.get_vertex_size(), infty_),
        prev_vertex_(G.get_vertex_size(), -1){
        
    }

    /**
     * @brief 頂点 `s` から他の全頂点への最短距離を求める。
     * @note 到達不能の場合、`infty` となる。
     * @param s 始点の頂点
     */
    void solve(Vertex s){
        if(start_vertex_ == s) return;
        distance_.assign(distance_.size(), infty_);
        prev_vertex_.assign(prev_vertex_.size(), -1);
        distance_[s] = 0;
        using P = pair<CostType, Vertex>;
        priority_queue<P, vector<P>, greater<P>> que;
        que.emplace(0, s);
        while(que.size()){
            auto [d, v] = que.top(); que.pop();
            if(distance_[v] != d) continue;
            for(Edge<CostType> &e : graph_[v]){
                CostType nd = d + e.cost;
                if(nd < distance_[e.to]){
                    distance_[e.to] = nd;
                    prev_vertex_[e.to] = v;
                    que.emplace(nd, e.to);
                }
            }
        }
        start_vertex_ = s;
    }

    /**
     * @brief 頂点 `s` から頂点 `t` に到達可能かを返す。
     * 
     * @param s 始点の頂点
     * @param t 終点の頂点
     * @return true 到達可能
     * @return false 到達不能
     */
    bool reachable(Vertex s, Vertex t){
        solve(s);
        return distance_[t] != infty_;
    }

    /**
     * @brief 頂点 `s` から頂点 `t` への最短パスを返す。
     * @attention 頂点 `s` から頂点 `t` に到達不能の場合、空列を返す。
     * @param s 始点の頂点
     * @param t 終点の頂点
     * @return vector<Vertex> 最短パスに含まれる頂点列を `s` から `t` の順に並べたもの。到達不能の場合は空列が返される。
     */
    vector<Vertex> restore(Vertex s, Vertex t){
        if(!reachable(s, t)) return vector<Vertex>{};
        vector<Vertex> ret{t};
        Vertex v = t;
        while(v != s){
            v = prev_vertex_[v];
            ret.push_back(v);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }

    CostType operator[](Vertex t){
        return distance_[t];
    }
};