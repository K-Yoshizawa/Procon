/**
 * @file Dijkstra.hpp
 * @author log_K (lX57)
 * @brief Dijkstra - 単一始点最短距離
 * @version 2.0
 * @date 2023-08-31
 */

#include "GraphTemplate.hpp"

template<typename CostType>
struct Dijkstra{
    private:
    Graph<CostType> &G;
    vector<CostType> __Dist;
    vector<Vertex> __PrevVertex;
    Vertex __Start;

    void __solve(){
        __Dist.assign(G.vsize(), G.INF);
        __PrevVertex.assign(G.vsize(), -1);
        using p = pair<CostType, Vertex>;
        priority_queue<p, vector<p>, greater<p>> que;
        que.emplace(0, __Start);
        __Dist[__Start] = 0;
        while(que.size()){
            auto [d, v] = que.top(); que.pop();
            if(__Dist[v] < d) continue;
            for(Edge<CostType> &e : G.get_incident(v)){
                if(d + e.cost < __Dist[e.to]){
                    __Dist[e.to] = d + e.cost;
                    __PrevVertex[e.to] = v;
                    que.emplace(d + e.cost, e.to);
                }
            }
        }
    }

    public:
    Dijkstra(Graph<CostType> &G) : G(G), __Dist(G.vsize()), __PrevVertex(G.vsize()), __Start(-1){}
    
    Dijkstra(Graph<CostType> &G, Vertex Start) : G(G), __Dist(G.vsize()), __PrevVertex(G.vsize()), __Start(Start){
        __solve();
    }

    void build(Vertex Start){
        assert(0 <= Start && Start < G.vsize());
        if(Start != __Start){
            __Start = Start;
            __solve();
        }
    }

    CostType dist(Vertex Start, Vertex Goal){
        assert(0 <= Start && Start < G.vsize());
        assert(0 <= Goal && Goal < G.vsize());
        if(Start != __Start){
            __Start = Start;
            __solve();
        }
        return __Dist[Goal];
    }

    void print(bool DisplayINF = true, char Delimiter = ' '){
        cout << (DisplayINF && __Dist[0] == G.INF ? "INF" : to_string(__Dist[0]));
        for(int i = 1; i < (int)__Dist.size(); ++i){
            cout << Delimiter << (DisplayINF && __Dist[i] == G.INF ? "INF" : to_string(__Dist[i]));
        }
        cout << endl;
    }
};