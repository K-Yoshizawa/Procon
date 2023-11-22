#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"

#include "../icpc/Dijkstra.hpp"

int main(){
    int V, E, r; cin >> V >> E >> r;
    GR g(V);
    for(int i = 0; i < E; ++i){
        int s, t, d; cin >> s >> t >> d;
        g[s].push_back({t, d});
    }

    auto dist = dijkstra(g, r);
    for(auto d : dist){
        (d == INF ? cout << "INF" << endl : cout << d << endl);
    }
}