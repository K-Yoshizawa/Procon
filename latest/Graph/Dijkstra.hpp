/**
 * @file Dijkstra.hpp
 * @author log_K (lX57)
 * @brief Dijkstra - 単一始点最短距離
 * @version 2.1
 * @date 2023-08-31
 */

#include "GraphTemplate.hpp"

template<typename CostType>
struct Dijkstra{
    private:
    Graph<CostType> &G;
    vector<CostType> __Dist, __Potential;
    vector<Vertex> __PrevVertex;
    vector<pair<EdgeID, bool>> __PrevEdge;
    Vertex __Start;

    void __solve(){
        __Dist.assign(G.vsize(), G.INF);
        __PrevVertex.assign(G.vsize(), -1);
        __PrevEdge.assign(G.vsize(), {-1, false});
        using p = pair<CostType, Vertex>;
        priority_queue<p, vector<p>, greater<p>> que;
        que.emplace(__Potential[__Start], __Start);
        __Dist[__Start] = __Potential[__Start];
        while(que.size()){
            auto [d, v] = que.top(); que.pop();
            if(__Dist[v] < d) continue;
            for(auto [eid, rev] : G.get_raw_incident(v)){
                Edge<CostType> e = G.get_edge(eid, rev);
                if(e.cap > 0 && d + e.cost + __Potential[e.from] - __Potential[e.to] < __Dist[e.to]){
                    __Dist[e.to] = d + e.cost + __Potential[e.from] - __Potential[e.to];
                    __PrevVertex[e.to] = v;
                    __PrevEdge[e.to] = {eid, rev};
                    que.emplace(__Dist[e.to], e.to);
                }
            }
        }
        for(Vertex i = 0; i < G.vsize(); ++i){
            if(__Dist[i] != G.INF) __Dist[i] += __Potential[i] - __Potential[__Start];
        }
    }

    public:
    Dijkstra(Graph<CostType> &G) : G(G), __Dist(G.vsize()), __Potential(G.vsize(), 0), __PrevVertex(G.vsize()), __PrevEdge(G.vsize()), __Start(-1){}
    
    Dijkstra(Graph<CostType> &G, Vertex Start) : G(G), __Dist(G.vsize()), __PrevVertex(G.vsize()), __PrevEdge(G.vsize()), __Potential(G.vsize(), 0), __Start(Start){
        __solve();
    }

    void update_potential(vector<CostType> Potential){
        assert(__Potential.size() == Potential.size());
        __Potential = Potential;
    }

    void rebuild(){
        __solve();
    }

    void build(Vertex Start){
        assert(0 <= Start && Start < G.vsize());
        if(Start != __Start){
            __Start = Start;
            __solve();
        }
    }

    vector<CostType> all(Vertex Start){
        assert(0 <= Start && Start < G.vsize());
        if(Start != __Start) build(Start);
        return __Dist;
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

    vector<pair<CostType, bool>> restore_edge(Vertex Goal){
        vector<pair<CostType, bool>> ret;
        Vertex now = Goal;
        while(__PrevEdge[now].first != -1){
            ret.push_back(__PrevEdge[now]);
            auto [eid, rev] = __PrevEdge[now];
            now = G.get_edge(eid, rev).from;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }

    void print(bool DisplayINF = true, char Delimiter = ' '){
        cout << (DisplayINF && __Dist[0] == G.INF ? "INF" : to_string(__Dist[0]));
        for(int i = 1; i < (int)__Dist.size(); ++i){
            cout << Delimiter << (DisplayINF && __Dist[i] == G.INF ? "INF" : to_string(__Dist[i]));
        }
        cout << endl;
    }
};