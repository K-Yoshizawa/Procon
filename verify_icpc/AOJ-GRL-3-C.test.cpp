#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C"

#include "../icpc/StronglyConnectedComponents.hpp"

int main(){
    int V, E; cin >> V >> E;
    Graph G(V), rG(V);
    for(int i = 0; i < E; ++i){
        int s, t; cin >> s >> t;
        G[s].push_back({t, 1});
        rG[t].push_back({s, 1});
    }

    auto belong = scc(G, rG).first;
    int Q; cin >> Q;
    for(int i = 0; i < Q; ++i){
        int u, v; cin >> u >> v;
        cout << (belong[u] == belong[v]) << endl;
    }
}